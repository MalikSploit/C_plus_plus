//
// Created by malik on 12/28/2023.
//

#include <iostream>
#include <memory>

//smart pointers:
class Rectangle{
private:
    int length;
    int breadth;
public:
    Rectangle(int l, int b) : length(l), breadth(b){}
    [[nodiscard]] int area() const{
        return length*breadth;
    }
};
void unique_pointers(){
    // Create a new Rectangle and manage it with a unique_ptr.
    std::unique_ptr<Rectangle> ptr(new Rectangle(10,5));

    // Print the area of the Rectangle.
    std::cout << ptr->area() << std::endl;

    // Declare another unique_ptr
    std::unique_ptr<Rectangle> ptr2;

    // Transfer ownership of the Rectangle from ptr to ptr2. After this, ptr becomes null.
    ptr2 = std::move(ptr);

    // Print the area of the Rectangle, using ptr2.
    std::cout << ptr2->area() << std::endl;
}
void shared_pointers(){
    // Create a new Rectangle and manage it with a shared_ptr.
    std::shared_ptr<Rectangle> ptr(new Rectangle(10,5));

    // Print the area of the Rectangle.
    std::cout <<ptr->area() << std::endl;

    // Declare another shared_ptr
    std::shared_ptr<Rectangle> ptr2;

    // Share ownership of the Rectangle with ptr2
    ptr2 = ptr;

    // Print the area of Rectangle using both pointers.
    // It's the same Rectangle, so the area will be the same.
    std::cout << "ptr2 : " << ptr2->area() << std::endl;
    std::cout << "ptr : " << ptr->area() << std::endl;

    // Print out the reference count (which should be 2, since ptr and ptr2 are both managing the Rectangle).
    std::cout << "pointer count : " <<ptr.use_count() << std::endl;
}
void weak_pointers() {
    std::shared_ptr<Rectangle> shared1(new Rectangle(10, 5));
    std::shared_ptr<Rectangle> shared2;
    std::weak_ptr<Rectangle> weak1;

    // Shares ownership of same memory as shared1
    shared2 = shared1;
    std::cout << "shared2's use count: " << shared2.use_count() << "\n";

    // Shares ownership but does not increase count
    weak1 = shared1;
    std::cout << "After assigning to weak_ptr, use count: " << shared1.use_count() << "\n";

    // Removes shared1's ownership from memory
    shared1.reset();
    std::cout << "After resetting shared1, use count: " << shared2.use_count() << "\n";

    // Checks if memory is still available
    if(auto spt = weak1.lock()) {
        std::cout << "Memory is still available! Area: " << spt->area() << "\n";
    }
    else {
        std::cout << "Memory has been deallocated.\n";
    }
}



int main(){
    unique_pointers(),
    shared_pointers();
    weak_pointers();
}