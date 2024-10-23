#include <iostream>

//Protype
class Document {
    public:
      virtual ~Document() = default;
      virtual Document* clone() const = 0;
      virtual void print() const = 0; 
};

class OriginalDocument : public Document {
    private:
      std::string m_content;
    public:
      OriginalDocument(const std::string& content) : m_content(content) {}
      Document* clone() const override {
        return new OriginalDocument(*this);
      }
      void print() const {
        std::cout << "Original Document's content: " << m_content << std::endl;
      }
};

class XeroxDocument : public Document {
    private:
      std::string m_content;
    public:
      XeroxDocument(const std::string& content) : m_content(content) {}
      Document* clone() const override {
        return new XeroxDocument(*this);
      }
      void print() const override {
        std::cout << "Xerox Document's content: " << m_content << std::endl;
      }
};

int main() {
    Document* doc = new OriginalDocument("It's a original doc.");
    doc->print();
    Document* doc_ = doc->clone();
    doc_->print();
    Document* xerox = new XeroxDocument("It's a xerox doc.");
    Document* xerox_doc = xerox->clone();
    xerox_doc->print();
    delete doc;
    delete xerox;
    delete doc_;
    delete xerox_doc;
}

