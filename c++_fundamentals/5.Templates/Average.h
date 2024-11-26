// Template Class to calculate the average of two values
template <typename T>
class Average {
    public:
        Average(T a, T b) : a(a), b(b) {} // Constructor

        T getAverage() const {
            return (a + b) / 2.0;
        }

    private:
        T a, b;
};

// Template Specialization
// Template specialization is a way to tell the compiler to treat a specific data type differently than it would normally do with a template.

// Template specialization for char type to calculate the average of two characters
template <>
class Average<char> {
    public:
        Average(char a, char b) : a(a), b(b) {} // Constructor

        char getAverage() const {
            return static_cast<char>((a + b) / 2);
        }

    private:
        char a, b;
};







