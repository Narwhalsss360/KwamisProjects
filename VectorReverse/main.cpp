#pragma once

#include<vector>
#include<iostream>
using namespace std;

void reverse(vector<int>::iterator begin, vector<int>::iterator end)
{
    // begin = 1, --end = 9
    // 9, 1
    // ++begin = 3, --end = 7
    // 7, 3
    // ++begin = 5, --end = 5
    // break;

    while (begin != end && begin != --end)
    {
        swap(*begin, *end);
        ++begin;
    }
}

vector<int> reverseCopy(const vector<int>& vec)
{
    //If the vector is empty, then just return an empty vector.
    if (vec.size() == 0)
        return vector<int>();

    //Create new copy.
    vector<int> reversedCopy = vector<int>(vec.size());

    //Have i count up starting from 0, have j count down starting from size - 1
    //Only stop once i is greater than size - 1. (i < size)
    for (int i = 0, j = vec.size() - 1; i < vec.size(); i++, j--)
    {
        //Copy from original index at j to copy index i.
        reversedCopy[i] = vec[j];
    }

    return reversedCopy;
}

void reverseOriginal(vector<int>& vec)
{
    //Have i count up starting from 0, have j count down starting from size - 1.
    //Only stop once we reach the middle (i != j)
    for (int i = 0, j = vec.size() - 1; i != j; i++, j--)
    {
        //Swap the elemets at i and j.
        swap(vec[i], vec[j]);
    }
}

int main()
{
    // Get the vector
    vector<int> a = { 1, 3,5, 7, 9 };

    // Print the vector
    cout << "Vector: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    // Reverse the vector
    reverse(a.begin(), a.end());

    // Print the reversed vector
    cout << "Original Reversed Vector: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    //Create a copy but reversed.
    vector<int> aReversedCopy = reverseCopy(a);

    cout << "Reversed Copy: ";
    for (int i = 0; i < aReversedCopy.size(); i++)
        cout << aReversedCopy[i] << " ";
    cout << endl;

    cout << "Original Reversed Vector: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    //Reverse the original.
    reverseOriginal(a);

    // Print the vector
    cout << "Original re-reversed Vector: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}