/***********************************************************************
This program is intended to demonstrate the operations of an ADT array *
************************************************************************/

/************************************************************************************************************************************************************************
Pass by value: makes a copy of the value being passed  -> int x = 10; foo(x); void foo(int a){ a = 11; }  ->  a = 11, x = 10                                            *
Pass by reference: changes data being passed as an argument during func execution -> int x = 10; foo(x); void foo(int& a){ a = 11; }  ->  a = 11, x = 11;               *
Pass by pointer or pass by address: need to pass in a pointer variable(*x) or an address(&x) -> int x = 10; foo(&x); void foo(int* a){ *a = 11; } -> a = 11, x = 11;    *
*************************************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>

/*********** 
Prototypes *
************/
void create();
void call(struct Array*);
void display(struct Array*);
void push(struct Array*, int);
void insert(struct Array*, int, int);
void remove(struct Array*, int);
int linearSearch(struct Array*, int);
int countOccurrences(struct Array*, int);
int binarySearch(struct Array*, int);
void bubbleSort(struct Array*);
int get(struct Array*, int);
bool set(struct Array*, int, int);
int max(struct Array*);
int min(struct Array*);
void reverse(struct Array*);
void shiftLeft(struct Array*);
void shiftRight(struct Array*);
void rotate(struct Array*);
void swap(int*, int*);
int sum(struct Array*);
void random(struct Array*);
void merge(int*, int, int);
void mergeSort(struct Array*, int, int);

/****************************************************************************************************************************************************
int *ptr is the pointer pointing to the struct(also element 0); ptr is a pointer in the <Heap> pointing to the struct Array objects in the <Stack>  *
*****************************************************************************************************************************************************/
struct Array{
    int *ptr;
    int size;
    int length;
};

int main(){
    create();
}
/**************************************************************************************************************************************************
This function will prompt the user to create the array by using struct Array data type by determining the size, length, and elements of the array *
***************************************************************************************************************************************************/
void create(){
// create a variable of type "Array" and initialize; get size from user; now that size is known, create an array for the pointer *ptr   
    std::cout << std::setfill('*') << std::setw(21) << "*" << "  CREATE AN ARRAY  " << std::setw(21) << "*"  << std::endl;
    struct Array arr{};
    int i, length;
    arr.length = 0;
    
    std::cout << "Enter size of the array: ";
    std::cin >> arr.size;
    arr.ptr = new int(arr.size); // dynamically allocated memory(created in the <Heap>) arr.ptr = (int *)malloc(arr.size * sizeof(int)); #include <stdlib.h>
                                                                                                                                           
// since there are no elements; set the array length to 0; prompt for the number of elements; set length = # of elements; use for-loop to populate array; then call display() *
    
    std::cout << "Enter number of elements in array: ";
    std::cin >> length;

    std::cout << "Enter all elements:" << std::endl;
    for(i = 0; i < length; i++){
        std::cin >> arr.ptr[i];
    }
    arr.length = length; // length = arr.length(program will not operate correctly)

/***************
Call functions *
****************/
    call(&arr);
}

/******************************************************************************
This function will be responsible to prompting the user and calling functions  *
*******************************************************************************/
void call(struct Array *arr){
    int option, element, index, key, occurs, len;
    int c_arr[arr->length];
    bool set_bit, m_bit = false;
    bool goAgain = true;

    while(goAgain){
        std::cout << std::setfill('*') << std::setw(20) << "*" << "  ARRAY PERFORMANCE  " << std::setw(20) << "*"  << std::endl;
        std::cout << "0 to display\n1 to append\n2 to insert\n3 to remove\n4 to linear search\n5 to sort array\n6 to count occurrences\n7 to binary search";
        std::cout << "\n8 to randomize array\n9 get element\n10 to set value at index\n11 to get max element\n12 to get min element\n13 to reverse array";
        std::cout << "\n14 to find sum of all elements\n15 shift elements to the left\n16 shift elements to the right\n17 rotate array\n999 to end program: ";

        std::cin >> option;

        switch(option) {
        // display
            case 0:
                break;
        // append
            case 1:
                std::cout << "Which integer would you like to append? ";
                std::cin >> element;
                push(arr, element);
                break;
        // insert
            case 2:
                printf("At what index and which element? ");
                std::cin >> index >> element;
                insert(arr, index, element);
                break;
        // remove
            case 3:
                std::cout << "Which index would you like to remove? ";
                std::cin >> index;
                remove(arr, index);
                break;
        // linearSearch
            case 4:
                std::cout << "Which element would you like to search for? ";
                std::cin >> key;

                index = linearSearch(arr, key);
                if (index == -1) {
                    std::cout << key << " is not in the array...\n";
                } else {
                    occurs = countOccurrences(arr, key);
                    if (occurs > 1) {
                        std::cout << "There are " << occurs << " occurrences in the array. The first occurrence is at index " << index << "."
                                  << std::endl;
                    } else {
                        std::cout << key << " is at index " << index << std::endl;
                    }
                }
                break;
        // bubbleSort
            case 5:
                std::cout << "Sorted array." << std::endl;
                bubbleSort(arr);
                display(arr);
                break;
        // countOccurrences
            case 6:
                std::cout << "I will count the occurrences of your element. Which element should I search for? ";
                std::cin >> key;

                occurs = countOccurrences(arr, key);
                switch (occurs) {
                    case 0:
                        std::cout << "There are no occurrences of the element " << key << " found in the array...." << std::endl;
                        break;
                    case 1:
                        std::cout << "The element " << key << " is found " << occurs << " time in the array." << std::endl;
                        break;
                    default:
                        std::cout << "The element " << key << " is found " << occurs << " times in the array."
                                  << std::endl;
                        break;
                }
                break;
        // binSearch & bubbleSort
            case 7:
                bubbleSort(arr); // list must be sorted to perform binary-search

                std::cout << "Which element would you like to find? ";
                std::cin >> key;
                index = binarySearch(arr, key);

                if (index == -1) {
                    std::cout << "Element " << key << " was not found in the array." << std::endl;
                } else {
                    std::cout << "Element " << key << " was found at index " << index << "." << std::endl;
                }
                break;
        // shuffle
            case 8:
                random(arr);
                break;
        // get
            case 9:
                std::cout << "Which index would you like to get? ";
                std::cin >> index;

                element = get(arr, index);
                if (element == -1) {
                    std::cout << "Index " << index << " does not exist in the array...Choose an index from 0 to " << arr->length - 1 << std::endl;
                } else {
                    std::cout << get(arr, index) << " is found at index " << index;
                }
                break;
        // set
            case 10:
                std::cout << "Which index would you like to set and with which integer? ";
                std::cin >> index >> element;

                set_bit = set(arr, index, element);
                if (set_bit) {
                    std::cout << "Element set at index " << index << std::endl;
                } else {
                    std::cout << "Index " << index << " does NOT exist in the array...Choose an index from 0 to " << arr->length - 1 << std::endl;
                }
                break;
        // max
            case 11:
                std::cout << "The maximum element in the array is " << max(arr) << std::endl;
                break;
        // min
            case 12:
                std::cout << "The minimum element in the array is " << min(arr) << std::endl;
                break;
        // reverse
            case 13:
                reverse(arr);
                break;
        // sum
            case 14:
                std::cout << "The sum of all elements in the array is " << sum(arr) << std::endl;
                break;
        // shiftLeft
            case 15:
                shiftLeft(arr);
                break;
        // shiftRight
            case 16:
                shiftRight(arr);
                break;
        // rotate
            case 17:
                rotate(arr);
                break;
        // exit program
            case 999:
                std::cout << std::endl << "Ending program...";
                goAgain = false;
                break;
        // bad input
            default:
                std::cout << "Invalid input..." << std::endl << std::endl;
                goAgain = false;
                call(arr);
                break;
        }
        display(arr);
    }
}

/********************************************************************************************************************************
This function uses a for-loop to display elements of the array by using the Struct Array arr as a parameter to access the array *
*********************************************************************************************************************************/
void display(struct Array *arr){
    std::cout << std::setfill('*') << std::setw(26) << "*" << "  ARRAY  " << std::setw(26) << "*" << std::endl;
    int i;

    for(i = 0; i < arr->length; i++){
        printf("[%d]", arr->ptr[i]); // *ptr is used to access the array since *ptr is access to the array pointing to the first element
    }
    std::cout << std::endl;
}

/****************************************************************************************************************************************************************************
This function is responsible for adding a new element to the end of the array; check if there is room in the array to add; if so add new element, else prompt user of issue *
*****************************************************************************************************************************************************************************/
void push(struct Array *arr, int element){ // pass by pointer to update the array at its location in memory
    bool check = (arr->length == arr->size);
    
    if(check){
      puts("There is no more space in the array to append!");
    }else{
        arr->ptr[arr->length++] = element; //length is where the free space is since the elements start from 0; increment length
    }
}

/****************************************************************************************************************************************************************
This function will start at the index provided and shift the elements forward to the right one space; then replace that index with the element parameter given  *
min: O(1) max: O(n)                                                                                                                                             *
*****************************************************************************************************************************************************************/
void insert(struct Array *arr, int index, int element){
    int i;
    bool check = (index >= 0 && index <= arr->length && arr->length < arr->size);
    
    if(check){ //insure there is room to insert
//Start loop or i at the end of the elements(length), then loop through each element stopping at the index where new element is to be inserted, decrement to the left
        for(i = arr->length; i > index; i--){
            arr->ptr[i] = arr->ptr[i - 1]; //copy the element in front of the current i position
        }
        arr->ptr[index] = element; //once the shifting has stopped, this is where the element is inserted at the given index
        arr->length++;
    }else{
        std::cout << "There is no more space in the array to insert!" << std::endl;
    }
}

/***********************************************************************************************************************************
This function will delete an index in the array by shifting the elements from the right one space to the left to fill in the gap   *
************************************************************************************************************************************/
void remove(struct Array *arr, int index){
    int i;
    bool check = (index >= 0 && index < arr->length);

    if(check){ 
        for(i = index; i < arr->length - 1; i++){ // since one element is getting deleted 'less than' is the best option, len -1 since it's the last index with an element
        arr->ptr[i] = arr->ptr[i + 1]; // shifting elements to the left
        }
    }else{
        std::cout << "That is an invalid index. It must be greater than 0 and less than " << arr->length << std::endl;
    }
    arr->length--;
}

/****************************************************************************************************************************************************************************
This function will sequentially search the array for a specific key or specified element in the array and return the index of the first occurrence at which the key is found  *
*****************************************************************************************************************************************************************************/
int linearSearch(struct Array *arr, int key){
    int i;
    for(i = 0; i < arr->length; i++){
        if(key == arr->ptr[i]){ // find first occurrences of key
           return i;
        }
    }  
    return -1;  
}

/********************************************************************************************************
This function will perform as a linear search but will return the number of occurrences of a key element *
*********************************************************************************************************/
int countOccurrences(struct Array *arr, int key){
    int i, occurs = 0;
    
    for(i = 0; i < arr->length; i++){
        if(key == arr->ptr[i]){
            occurs++;
        }
    }
    return occurs;
}

/************************************************************************************************************************************************************************
This function will sort the array from smallest to greatest element size by comparing the first two elements of the array and checking if the first element is greater  *
than the second element; if so, swap those elements and move forward to the next element                                                                                *
*************************************************************************************************************************************************************************/
void bubbleSort(struct Array *arr){
    int i, j;
    
    for(i = 0; i < arr->length - 1; i++){
        for(j = 0; j < arr->length - 1 - i; j++){ 
            if(arr->ptr[j] > arr->ptr[j + 1]){ 
                swap(&arr->ptr[j], &arr->ptr[j + 1]);
            }
        }
    }
}

/****************************************************************************************************************************************************************************
This function works by divide and conquer by using subsets of the array to reduce time complexity by continual division of the array. **Array must be sorted **             *
The mid index is the one getting evaluated for the key, depending on if the key is lower or higher than the value at the index, determines if check right or left of mid    *
Think of low being the lower bound, high being the higher bound and mid being the center bound                                                                              *
where: low = smallest index, mid = middle index, high = high index  -->  continue to divide the array into subsets until key is found or until low > high indicating key NF *
if key is found return the index(mid) else, return -1(NF)   note: if odd number array size, mid will eventually equal low                                                   *                
*****************************************************************************************************************************************************************************/
int binarySearch(struct Array *arr, int key){
    int high, mid, low = 0;
    high = arr->length - 1; // -1 since we are dealing with index; setting high = length would cause an extra unnecessary search

    while(low <= high){ // if low > high then element is not found
        mid = ((low + high) / 2);

        if(key == arr->ptr[mid]){
            return mid;
        }else if(key < arr->ptr[mid]){ // key is on left side
            high = mid - 1; // mid has already been evaluated, so move high one element to the left of previous of mid previous index
        }else{ // key is on right side,
            low = mid + 1; // mid has already been evaluated, so move low one element to the right of previous mid previous index
        }
    }
    return -1;
}

/***************************************************
This function returns the element at a given index *
****************************************************/
int get(struct Array *arr, int index){
    bool check = (index >= 0 && index < arr->length);

    if(check){
        return arr->ptr[index];
    }else{
        return -1;
    }
}

/****************************************************************************************************
This function takes in an index and element and replaces the old element with the new given element *
*****************************************************************************************************/
bool set(struct Array *arr, int index, int element){
    bool check = (index >= 0 && index < arr->length);

    if(check){
        arr->ptr[index] = element;
        return true;
    }
    return false;
}

/****************************************************************************************************************************************************************************
This function finds and returns the largest number in the array. If the list is sorted, return the max index, else traverse entire list and return index where max is found *
*****************************************************************************************************************************************************************************/
int max(struct Array *arr){ // assume array is not sorted
    int i, max = arr->ptr[0];

    for(i = 0; i < arr->length; i++){
        if(max < arr->ptr[i]){ 
            max = arr->ptr[i];
        }
    }
    return max;
}

/*****************************************************************************************************************************************************************************
This function finds and returns the smallest number in the array. If the list is sorted, return the min index, else traverse entire list and return index where min is found *
******************************************************************************************************************************************************************************/
int min(struct Array *arr){ // assume array is not sorted
    int i, min = arr->ptr[0];

    for(i = 0; i < arr->length; i++){
        if(min > arr->ptr[i]){ 
            min = arr->ptr[i];
        }
    }
    return min;
}

/***************************************************************************************************************************************************************************
This function will reverse the array by swapping elements at i with element at j using the swap function. Step through the array from beginning to end and meeting in the  *
middle. Do this by setting i = 0th index and adding 1 until i < middle element and simultaneously setting j = len - 1 index and subtracting 1 until j >= middle element.   *
In this algorithm, i should never equal j or visa-versa. The condition to stop the code is when i and j indices are contiguous.  Time: O(n)                               *
****************************************************************************************************************************************************************************/
void reverse(struct Array *arr){
    int i, j;
   
    for(i = 0, j = arr->length - 1; i < j; i++, j--){
        swap(&arr->ptr[i], &arr->ptr[j]);
    }
}

/************************************************************************************************************************************************************************
This function will take in two pointers, pointing to the elements of an array and swap them by using a temp variable. Given that the elements are pass-by-pointer, the  *
swap will successfully make permanent modifications to the array's sequence of elements until they are changed again by this function or another form of swapping.      *
*************************************************************************************************************************************************************************/
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/************************************************************************************************************************************************
This function will shift each element one space to the left, so the element at index 0 will be lost and become a free space and  will become 0; *
*************************************************************************************************************************************************/
void shiftLeft(struct Array *arr){
    int i;
    for(i = 0; i < arr->length - 1 ; i++){
        swap(&arr->ptr[i], &arr->ptr[i + 1]);
    }
}

/*************************************************************************************************************************************************************************
This function will shift each element one space to the right, so the element at the last index will be lost and become a free space and the first element will become 0  *
'last element descends'
**************************************************************************************************************************************************************************/
void shiftRight(struct Array *arr){
    int i;
    for(i = arr->length - 1; i > 0; i--){
        swap(&arr->ptr[i], &arr->ptr[i - 1]);
    }
}

/************************************************************************************************************************
This function will rotate the array by switching element at index 0 with the last element at index arr->length - 1 O(n) *
*************************************************************************************************************************/
void rotate(struct Array *arr){
    swap(&arr->ptr[0], &arr->ptr[arr->length - 1]);
}

/**********************************************************************************************
This function will traverse the array and find the sum of all the elements and return the sum *
***********************************************************************************************/
int sum(struct Array *arr){
    int i, sum = 0;

    for(i = 0; i < arr->length; i++){
        sum += arr->ptr[i];
    }
    return sum;
}

/****************************************
This function will randomize the array  *
****************************************/
void random(struct Array *arr){
    srand(time(0));
    int i, r, t = rand() % arr->length;
    r = rand() % arr->length;

    for(i = 0; i < arr->length; i++){
        while(r == t){
            r = rand() % arr->length;
        }
        swap(&arr->ptr[r], &arr->ptr[t]);
    }
}

