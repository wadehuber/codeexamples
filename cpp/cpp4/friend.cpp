#include<iostream>
#include<string>

using namespace std;

class WordNode {
    private:
        string word;
        WordNode * next;
    public:
        explicit WordNode(const string & s) : word{s} {
            next = nullptr;
        }

        friend class WordList;
        friend ostream& operator<<(ostream& strm, const class WordList& m);
};

class WordList {
    private:
        int size;
        WordNode * first;
        WordNode * last;

    public:
        WordList() : size(0), first(nullptr), last(nullptr) {}

        ~WordList() {
            WordNode *curr = first;
            WordNode * ptr;

            while (curr) {
                ptr = curr;
                curr = curr->next;
                delete(ptr);
                ptr = nullptr;
            }
            curr = nullptr;
            first = nullptr;
            last = nullptr;
        }

        void addToFront(string s);
        void addToRear(string s);
        bool isEmpty() const { return ( size == 0 ); }

        friend ostream& operator<<(ostream& strm, const WordList& m);
};

void WordList::addToFront(string s) {
    WordNode * newWordNode = new WordNode(s);
    newWordNode->next = first;
    first = newWordNode;
    size++;
    if (size == 1) {
        last = first;
    }
}

void WordList::addToRear(string s) {
    WordNode * newWordNode = new WordNode(s);
    if (isEmpty()) {
        addToFront(s);
    }
    else {
        last->next = newWordNode;
        last = newWordNode;
        size++;
    }
}

ostream& operator<<(ostream& strm, const WordList& m) {
    WordNode * curr = m.first;
    while (curr) {
        strm << curr->word << " ";
        curr = curr->next;
    }
    return strm;
}

int main () {

    WordList words;

    words.addToFront("Hello");
    words.addToRear("World");
    words.addToRear("goodbye");
    words.addToFront("CSC220");

    cout << words << endl;

    return 0;
}
