// ex3.cpp -- functions and structures
#include <iostream>

using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void display_box(box);
void set_volume(box *);

int main()
{
    box mybox;

    cout << "Enter the maker: ";
    cin >> mybox.maker;
    cout << "Enter the height: ";
    cin >> mybox.height;
    cout << "Enter the width: ";
    cin >> mybox.width;
    cout << "Enter the length: ";
    cin >> mybox.length;

    set_volume(&mybox);
    display_box(mybox);

    return 0;
}

void display_box(box mybox)
{
    cout << "Maker: " << mybox.maker << endl;
    cout << "Height: " << mybox.height << endl;
    cout << "Width: " << mybox.width << endl;
    cout << "Length: " << mybox.length << endl;
    cout << "Volume: " << mybox.volume << endl;
}

void set_volume(box * p_mybox)
{
    double volume = p_mybox->height * p_mybox->width * p_mybox->length;
    p_mybox->volume = volume;
}
