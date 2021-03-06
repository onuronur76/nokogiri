#ifndef NOKOGIRI_XML_DOCUMENT
#define NOKOGIRI_XML_DOCUMENT

#include <nokogiri.h>

struct _nokogiriTuple {
  VALUE         doc;
  st_table     *unlinkedNodes;
  VALUE         node_cache;
};
typedef struct _nokogiriTuple nokogiriTuple;
typedef nokogiriTuple * nokogiriTuplePtr;

void init_xml_document();
VALUE nokogiri_xml_document_wrap_with_init_args(VALUE klass, xmlDocPtr doc, int argc, VALUE *argv);
VALUE nokogiri_xml_document_wrap(VALUE klass, xmlDocPtr doc);

#define DOC_RUBY_OBJECT_TEST(x) ((nokogiriTuplePtr)(x->_private))
#define DOC_RUBY_OBJECT(x) (((nokogiriTuplePtr)(x->_private))->doc)
#define DOC_UNLINKED_NODE_HASH(x) (((nokogiriTuplePtr)(x->_private))->unlinkedNodes)
#define DOC_NODE_CACHE(x) (((nokogiriTuplePtr)(x->_private))->node_cache)

extern VALUE cNokogiriXmlDocument ;

/* deprecated. use nokogiri_xml_document_wrap() instead. */
VALUE Nokogiri_wrap_xml_document(VALUE klass, xmlDocPtr doc);

#endif
