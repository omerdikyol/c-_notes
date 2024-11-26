#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
    void sayHi() {
        std::cout << "Hi from Resource\n";
    }
};

// Smart Pointers (unique_ptr, shared_ptr, weak_ptr)

// unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
// No two unique_ptr instances can manage the same object, which ensures that the object is deleted exactly once.
void useUniqueResource() {
    std::unique_ptr<Resource> res(new Resource());
    res->sayHi();
}

// shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Multiple shared_ptr instances can manage the same object.
// The object is destroyed when the last shared_ptr managing it is destroyed or reset.
void useSharedResource() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>(); // make_shared is more efficient than using new Resource()
    {
        std::shared_ptr<Resource> res2 = res1;
        res2->sayHi();
        std::cout << "Shared resource use count: " << res1.use_count() << "\n";
    }
    std::cout << "Shared resource use count after inner scope: " << res1.use_count() << "\n";
}

// weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by shared_ptr.
// It is used to break circular references between shared_ptr instances.
void useWeakResource() {
    std::shared_ptr<Resource> res = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakRes = res;
    if (std::shared_ptr<Resource> sharedRes = weakRes.lock()) {
        sharedRes->sayHi();
    } else {
        std::cout << "Resource is no longer available\n";
    }
}

int main() {
    useUniqueResource();
    useSharedResource();
    useWeakResource();

    return 0;
}