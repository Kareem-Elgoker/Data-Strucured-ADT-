template <typename T>
class Array
{

private:

    T * arr;
    int MaxLen;
    int CurrLen;

public:


    Array(int n)
    {
        arr = new T[n];
        MaxLen = n;
        CurrLen = 0;
    }
    Array(): Array(0){}


    void Display() // O(N)
    {
        for (int i = 0; i < CurrLen; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    int GetLength()
    {
        return CurrLen;
    }

    bool IsFull()
    {
        return CurrLen == MaxLen;
    }

    bool IsEmpty()
    {
        return !CurrLen;
    }

    bool Append(T ele) // O(1), false indicates that the array is full.
    {
        if(IsFull()) return false;

        arr[CurrLen++] = ele;

        return true;
    }

    bool Insert(int index, T ele) // O(N), false indicates that the index is out of range or the array is full.
    {
        if(IsFull()) return false;
        if(index < 0 || index > CurrLen) return false;

        for (int i = index; i < CurrLen; ++i) {
            arr[i + 1] = arr[i];
        }
        arr[index] = ele;
        ++CurrLen;

        return true;
    }

    bool Delete(int index) // O(N), false indicates that the index is out of range.
    {
        if(index < 0 || index >= CurrLen) return false;

        for (int i = index; i < CurrLen; ++i) {
            arr[i] = arr[i + 1];
        }
        --CurrLen;

        return true;
    }

    int Search(T ele) // O(N), -1 indicates that the element is not found.
    {
        for (int i = 0; i < CurrLen; ++i) {
            if(arr[i] == ele)
                return i;
        }

        return -1;
    }

    T Get(int index) // O(1), NULL indicates that the index is out of range.
    {
        if(index < 0 || index >= CurrLen) return NULL;

        return arr[index];
    }

    bool Set(int index, T ele) // O(1), false indicates that the index is out of range.
    {
        if(index < 0 || index >= CurrLen) return false;

        arr[index] = ele;

        return true;
    }

    T Max() // O(N), NULL indicates that the array is empty.
    {
        if(IsEmpty()) return NULL;

        T MaxValue = arr[0];
        for (int i = 1; i < CurrLen; ++i) {
            if(arr[i] > MaxValue)
                MaxValue = arr[i];
        }

        return MaxValue;
    }

    T Min() // O(N), NULL indicates that the array is empty.
    {
        if(IsEmpty()) return NULL;

        T MinValue = arr[0];
        for (int i = 1; i < CurrLen; ++i) {
            if(arr[i] < MinValue)
                MinValue = arr[i];
        }

        return MinValue;
    }

    T Sum() // O(N)
    {
        T summation = 0;
        for (int i = 0; i < CurrLen; ++i) {
            summation += arr[i];
        }
        return summation;
    }

    double Average() // O(N)
    {
        if(IsEmpty()) return 0.0;

        return Sum() / (double)CurrLen;
    }
    bool Swap(int index1, int index2) // O(1), false indicates that the index is out of range.
    {
        if(index1 < 0 || index1 >= CurrLen) return false;
        if(index2 < 0 || index2 >= CurrLen) return false;

        T temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;

        return true;
    }

    void Reverse() // O(N)
    {
        for (int i = 0; i < CurrLen / 2; ++i) {
            Swap(i, CurrLen - i - 1);
        }
    }

    void Sort()
    {
        /*
         * You Can Write any Sorting Algorithm Here
         * I will Write Bubble Sort with O(N^2) just because it is easy.
         */

        for (int i = 0; i < CurrLen; ++i) {
            for (int j = 0; j < CurrLen; ++j) {
                if(arr[j] > arr[j + 1])
                    Swap(j, j + 1);
            }
        }

    }

    bool IsSorted() // O(N)
    {
        for (int i = 1; i < CurrLen; ++i) {
            if(arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }

    /*
     * O(LOG(N))
     * -1 indicates that the element is not found.
     * -2 indicates that the array is not sorted.
     */
    int BinarySearch(T ele)
    {
        if(!IsSorted()) return -2;

        int low = 0, high = CurrLen - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] == ele)
                return mid;
            else if(arr[mid] > ele)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }

    bool InsertInSortedPosition(T ele) // O(N), false indicates that the array is full.
    {
        if(IsFull()) return false;

        for (int i = 0; i < CurrLen; ++i) {
            if(arr[i] >= ele)
            {
                Insert(i, ele);
                break;
            }
        }

        return true;
    }

    bool AppendArray(Array<T> appended_array) // O(N), false indicates that the array will be full.
    {
        if(appended_array.GetLength() + CurrLen >= MaxLen) return false;

        for (int i = 0; i < appended_array.GetLength(); ++i) {
            Append(appended_array.Get(i));
        }

        return true;
    }
};
