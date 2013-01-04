#---
# Excerpted from "Agile Web Development with Rails, 4rd Ed.",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/rails4 for more book information.
#---
class CreateLineItems < ActiveRecord::Migration
  def self.up
    create_table :line_items do |t|
      t.integer :product_id
      t.integer :cart_id

      t.timestamps
    end
  end

  def self.down
    drop_table :line_items
  end
end
