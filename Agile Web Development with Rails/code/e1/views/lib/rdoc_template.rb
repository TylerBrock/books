#---
# Excerpted from "Agile Web Development with Rails, 4rd Ed.",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/rails4 for more book information.
#---
require 'rdoc/markup'
require 'rdoc/markup/to_html'

class RDocTemplate < ActionView::TemplateHandler
  include ActionView::TemplateHandlers::Compilable
  def compile(template)
    markup    = RDoc::Markup.new
    generator = RDoc::Markup::ToHtml.new
    markup.convert(template.source, generator).inspect
  end
end
