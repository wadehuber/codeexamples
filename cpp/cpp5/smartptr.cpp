#include<iostream>
#include<memory>

using namespace std;

int main() {

    shared_ptr<int> sptr1(new int(1));
    shared_ptr<int> sptr2(new int(2));
    unique_ptr<int> uptr3(new int(10));

    cout << "Shared pointer1: " << *sptr1 << endl; 
    cout << "Shared pointer2: " << *sptr2 << endl; 
    cout << "Unique pointer3: " << *uptr3 << endl; 
    cout << endl;

    *sptr1 = 3;
    cout << "sptr1 value changed" << endl;
    cout << "Shared pointer1: " << *sptr1 << endl; 
    cout << "Shared pointer2: " << *sptr2 << endl; 
    cout << "Unique pointer3: " << *uptr3 << endl; 
    cout << endl;

    sptr2 = sptr1;
    cout << "sptr2=sptr1 " << endl;
    cout << "Shared pointer1: " << *sptr1 << endl; 
    cout << "Shared pointer2: " << *sptr2 << endl; 
    cout << "Unique pointer3: " << *uptr3 << endl; 
    cout << endl;

    // sptr2 = new int(4);
    sptr2.reset(new int(4));
    cout << "sptr2 changed" << endl;
    cout << "Shared pointer1: " << *sptr1 << endl; 
    cout << "Shared pointer2: " << *sptr2 << endl; 
    cout << "Unique pointer3: " << *uptr3 << endl; 
    cout << endl;

    return 0;
}
