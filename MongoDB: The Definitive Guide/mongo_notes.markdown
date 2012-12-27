# Mongo Notes #

## General ##

 * Auto-generated API for JavaScript functions provided by mongo shell http://api.mongodb.org/js

### Why MongoDB? ###
  * Rich data model
    - row -> document (more object oriented)
    - Schema Free - data model dealt with at application level
  * Easy scaling
    - Mongo is designed to scale out, automatically split up data across commodity hardware
    - Programers can focus on building the app not scaling it
  * Features
    - Indexing (unique, compound, geospatial, and generic secondary indexes)
    - Stored JavaScript rather than stored procedures
    - Aggregation
    - Fixed size collections (capped collections useful for logs)
    - File storage
  * Missing Features (by design)
    - Joins
    - Multirow transactions
    
### Philosophy ###

Create a full featured datastore that is scalable, flexible, and fast.

  * Whenever possible offload processing and logic to client (either driver or application code)
    - This leads to increased performance
  * Simplify administration by having servers administer themselves whenever possible

### Good to know ###

#### Server ####
  * On startup the mongo client connects to the test database
  * When run with no arguments
    - uses default data dir '/data/db'
    - uses port 27017
    - web server is on port 28017
  * mongod can be started with --objcheck to validate structural validity before inserting to the database
  * collection names are limited to 121 bytes because the index on ".$_id_" takes up 6 the extra 6 would take you up to 127 bytes
  * One reason Mongo is fast is because it uses a binary wire protocol to avoid HTTP/REST overhead
  * Each connection has it's own queue of requests such that one can read their own writes consistantly
    - Drivers that use connection pooling may not experience this but have ways to enforce this
    
#### Shell ####
  * Conditionals are an inner document key and modifiers are outer document keys
  * `printjson` -- pretty prints the json
  * `db.runCommand({getLastError: 1})` -- prints the last op status
  * "$where" queries do not use the index
  * db.system.namespaces is hidden

#### Tools ####
  * mongoexport dumps collections to json but cannot serialize all types (use mongodump to preserve)

## Basics ##

### Types ###
 * JSON Types: null, boolean, numeric, string, array, object
 * JavaScript only supports 64-bit floating point numbers

### Databases ###
 * Each instance can have multiple databases
 * Databases are created at file level and are separate on disk

#### Names ####
 * Should be all lower case
 * Cannot contain '', '.', '$', '/', '\', '\0'
 * Cannot be the empty string ""
 * Limited to a maximum of 64 bytes

#### Special DBs ####
 * Admin
    - Root authentication DB
        - users added to admin db will inherit perms for all dbs
    - Listing DBs and shutting down server can only be done from this db
 * local
    - never gets replicated
 * config
    - used internally to store information about shards

### Collections ###

#### Reserved Names ####
 * The empty string "" is not a valid collection name
 * '\0' is used to signify the end of a collection
 * collection names should not start with "system." (system reserved)
 * '$' (although sometimes used by drivers)

#### Tips / Tricks ####
 * You can get a collection via db.getCollection("collection-name")

#### Sub Collections ####
 * Used for informational purposes only
 * Namespace delineated by '.' character
 * Ex: blog.posts

### Documents ###
 * Document size cannot exceed 4mb
    - To see BSON size in console run Object.bsonsize(document)
 * Key/value pairs in documents are ordered
 * Must have an "_id" key that is unique within collection
    - Can be any type but defaults to ObjectId

#### Reserved Keys ####
 * Keys are stored with UTF-8 character set
 * '\0' is used to signify the end of a key
 * '.' and '$' characters are reserved
 * Keys starting with '_' are reserved

#### Embeded Documents ####
 * Denormalizes data and trades efficiency and clarity for space
 * Can be indexed like arrays

##### ObjectIds #####
 * Lightweight, easy to generate, globally unique across machines
 * Use 12 bytes of storage (24 hex digits, 2 for each byte)
    - Timestamp (4 bytes)
    - Machine (3 bytes)
    - PID (2 bytes)
    - Increment (3 bytes)

## CRUD ##
 * Create -- `db.collection.insert(document)`
 * Read  -- `db.collection.find(query-document)`
 * Update -- `db.collection.update(query-document, new-document)`
 * Delete -- `db.collection.remove(query-doc)`

 * Save -- `db.collection.save(document)`
    - Inserts a document if it doesn't exist, updates it if it does
    - If document has an id save will do an upsert otherwise it will do an insert

### Notes ###
 * If no document is specified, the query document matches all documents!
 * If removing an entire collection use drop instead, it's faster
 * Dropping a collection will remove all indexes on that collection
 * Updates are atomic, last update will win
 * When updating, use unique attributes for query to avoid duplicate key error
 * When using modifiers, the value of "_id" cannot be changed

### Batch Inserts ###
 * Can be useful to avoid tcp/ip and db/collection header overhead
 * MongoDB does not accept messages longer than 16mb

### Upserts ###
 * Use by setting third parameter of update to `true`
    - Example: `db.collection.update(query-doc, update-doc, true)`
 * If no document is found that matches the update criteria, a new document is created
    - The new document will be created by combining the criteria and the update document

### Updating multiple documents ###
 * Pass `true` to the fourth parameter of update
 * Updates, by default, only update the first document found that matches criteria
 * One can see how many documents were updated by calling getLastError()
    - `db.runCommand({ getLastError: 1 })`

### Find and Modify ###
 * Use to return an item and update it in a single operation
 * Can either update or remove matching documents
 * usage: `db.runCommand({ findAndModify: collection, query: query-doc, sort: sort-criteria, update/remove: modifier doc or boolean, new: boolean })`
    - User must provide either update or remove but not both

### Safe Operations ###
 * The safe version of operations runs a getLastError command immediately following the operation
 * The response of getLastError is used to tell whether the operation succeeded or not

### Update -- Document Attributes ###
 * usage: `db.collection.update(query-doc, { $modifier: { key: val } })`

 * Scalar Update Modifiers: `$inc, $set, $unset`
 * Non-scalar Update Modifiers: `$push, $pop, $pull, $addToSet`
    - If push becomes a performance bottleneck then move array to new collection
 * `$pop: { key: 1 }` removes from the end of the array -- stack
 * `$pop: { key: -1 }` removes from the front of the array -- queue

#### Notes on Updating Document Attributes ####
 * Keys that don't exist will be created
 * `delete document.attribute` removes attribute
 * `$ne` can be added to query documents
    - Usage: `db.collection.update({ key: { $ne: value } }, ...)`
    - User can achieve similar effect with `$addToSet`
 * `$each` can be used with add to set to iterate and push unique array
    - Usage: `db.collection.update(query-doc, { $addToSet: { key: { $each: [thing1, thing2, thing3] } } })`

#### Positional Array Modifications ####
 * Example: `db.collection.update(query-doc, { $modifier: {"array.0.attribute": modification } })`
 * Position operator example: `db.collection.update(query-doc, { $modifier: {"array.$.attribute": modification } })`
    - Where query doc specifies array element to match

## Queries ##

### Find ###
 * `db.collection.find()` == `db.collection.find({ })`
    - Matches all documents in collection
 * Matching criteria -- `db.collection.find({ key: val })`
    - Multiple key: val pairs (conditionals) in query document serve as 'AND'
 * A second argument to find() and findOne() will specify fields to return
    - 1 will include a field, 0 will exclude a field

### Query Conditionals ###
 * scalar - `$lt, $lte, $gt, $gte`
 * non-scalar - `$in, $nin, $or, $all`

 * IN `db.collection.find({ key: { $in: [item1, item2] } })`
 * OR `db.collection.find({ $or: [{ key: val }, { key: val }] })`

 * $not is a metaconditional and can be applied on top of other criteria
 * Any number of conditionals can be put on a single key but only one modifier

#### Array conditionals ####
 * $all, $in, [] exact match
 * In general arrays can be treated as though each element is the overall key
 * Use $all to match by more than one element
 * Use { key: [val, val, val] } to perform an exact match -- order matters
 * One can also query using a specific index
 * db.food.find({"fruit.2": "peach"})

 * $size & $slice
 * db.food.find({"fruit": {"$size": 3}})

### Embedded Documents ###
 * Use $elemMatch to partially specify criteria to match a single embedded document in an array
 * $elemMatch allows you to group criteria so you can match more one key on an embedded document

### $where Queries ####
 * if function returns true, the document will be part of the result set

### Null ###
 * null matches null but also keys that do not exist
 * to find keys whose value is null:
    - db.collection.find({z: {$in: [null], $exists: true}})

## Indexing ##
 * Meta information is sorted in system.indexes collection of each database

`db.collection.ensureIndex({ key: 1/-1, ... })`
`db.collection.dropIndexes()`
`db.collection.dropIndex({ key: 1/-1, ... })`

 * Maximum of 64 indexes per collection
 * Sometimes the most efficient solution is actually not to use an index
    - When a query is returning half or more of the collection
    - Checking for existing key or whether boolean is true or false

### Unique Indexes ###
`db.collection.ensureIndex({ key: 1/-1, }, { unique: true })`

 * A unique index on "_id" is created whenever a collection is created
    - This index cannot be deleted

### Background Indexes ###
`db.collection.ensureIndex({ key: 1/-1, }, { background: true })`

## Cursors ##
 * You can make a cursor immortal by declaring it as such
    - If a cursor is not immortal it will time out in 10 minutes by default

## Replica Sets ##
 * Each replica set is limited to 12 total nodes and 7 voting nodes.

## Sharding ##

### Cluster Anatomy ###
 * shards -- for storing data
 * mongos -- for routing requests
 * config -- for cluster state

 * Chunks are defined with inclusive lower bound and exclusive upper bounds
    - Example: [4, 5)
 * Each document must belong to one and only one chunk
    - No overlapping chunks
    - No gaps between chunks
 * MongoDB does not allow you to insert documents that are missing a shard key
    - null is actually fine
 * You cannot change the value of a shard key (for example with $set)
    - The only way to give a document a new shard key is to remove and re-insert
 * Setting up sharding requires commands be run from the admin database
    
### Ordering of Types ###

Lowest precedence to highest

 * null
 * numbers
 * strings
 * objects
 * arrays
 * binary data
 * ObjectIds
 * booleans
 * dates
 * regular expressions

### Balancing ###
 * Balancing is automatic -- nice if you like the algorithm
 * The balancer moves chunks based on overall size of the shard
 * Goal is to keep data evenly distributed but also minimize data transfer
 * A shard must have at least 9 more chunks than the least-populous shard in order to trigger balancing
 * Default chunk-size is 2gb
    - Users can set chunk size via `--chunkSize N` (for N mb) in order to test

### Config Servers ###
 * If any config servers go down a cluster's configuration cannot change
 * Do not need replication, just start them as normal unconnected mongods
 
### Mongos ###
 * start with `mongos --configdb config1, config2, config3`
 * connect to the admin database `mongo server:port/admin`
 * add shards with `db.runCommand({ addShard: "server:port" })`
 * add replica sets with `db.runCommand({ addShard: "rs/server1,server2"})`
    - Limit shard size with maxSize `db.runCommand({ addShard: "...", maxSize: maxInMb })`
 * enable sharding via `db.adminCommand({ enableSharding: "database" })`
 * shard a collection: `db.adminCommand({ shardCollection: "database.collection", key: "key" })`
    - When sharding an existing collection make sure there is an index on the shard key
 * `db.printShardingStatus()` -- executive summary of sharding

### Shard Keys ###
 * Avoid low cardinality shard keys
 * Avoid strictly ascending/descending keys
 * Must be indexed -- don't waste an index on a key never used for queries (creates RAM pressure)
 * Generally good key formula: {coarseLocality: 1, search: 1}
    - Where coarseLocality is whatever locality you want for your data and search is a common search

## Decent Ideas ##
 * Create a better multi-line shell like irb or python
 * Add 32bit and 64bit int capability to JS console
    - being able to edit those values from the shell is valuable
 * Automatic closing brace, and parenthesis insertions
 * There should be a command to clear the screen in the client
 * Message "Thu Nov 17 10:25:40 [conn1] build index done 0 records 0 secs" on new collection creation is confusing; supress this one or replace it with something like new index instantiated
 * Stemming for full text search as per request in docs
 * Change _id to just be id (i get the idea but users can call theirs something else)

## Bugs ##
Syntax highlighting on the console breaks when open/close are over more than one line

## Questions ##
 * If db = test and users can reference fully qualified collection name test.blog.posts via db.blog.posts why not via test.blog.posts?
 * Why are arrays used as sets, should we use valueless documents for this (as python does)
 * Is there a way to do batch insertion on the shell? Possible that you can only do this with drivers
 * Is snapshotting a query efficient? (Does it actually snapshot the documents or fake by tracking '_id')
 * What is a sufficient number of documents to trigger chunking/balancing on a sharded setup

## Common Questions & Responses ##
 * Is MongoDB the right choice for my project?
    - "Users whose schema is either sparse, heirarchical, time varying, or heterogeneous find mongo to be a great fit."