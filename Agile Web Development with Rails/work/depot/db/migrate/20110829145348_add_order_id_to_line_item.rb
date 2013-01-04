class AddOrderIdToLineItem < ActiveRecord::Migration
  def self.up
    add_column :line_items, :order_id, :integer
  end

  def self.down
    remove_column :line_items, :order_id
  end
end
