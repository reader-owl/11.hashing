#include <iostream>

/*
(most imp topic) Hashing -  A hash table is a data structure which is used to store key-value 
                       pairs. Hash function is used by hash table to compute an index 
                       into an array in which an element will be inserted or searched.

                       gfg-
                       Hashing is a technique or process of mapping keys, and values into 
                       the hash table by using a hash function. It is done for faster 
                       access to elements. The efficiency of mapping depends on the 
                       efficiency of the hash function used.

            exam- lets have an array - {1, 2, 1, 3, 2}
                    now someone asks how many times the following nmbrs appear in the array
                    like -  '1' -> 2times
                            '3' -> 1times
                            '4' -> 0times
                            '2' -> 2times
                            '10' -> 0times  to find the nmbr of appearance we use Hashing

        Pseudo code(w/o hashing)
int f(nmbr, arr[])
{
    counter = o
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == nmbr)
            counter = counter + 1;
    }
    return counter;
}

                TC - O(q × N)   // q is the number of nmbrs(from above- '1', '3', '4', '2', '10')
                                // if we take a lot of nmbrs in a extreme long array, then it will 
                                // take huge amount of time to complete
                                // by this method nmbr or array length of '10^10' takes 100seconds
                                // to complete
                                // thats why will use HASHING

                Hashing - prestoring and fetching 

        Actual code (for hashing)
int main()
{
    int n;          // n = length of the array
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];      // array = {1, 3, 2, 1, 3}
    }

    // precompute
    int hash[13] = {0};     // hash array, maximum no of number which we want to find(12) + 1
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;      // q = number of numbers(which appear in array)
    cin >> q;
    while(q--)
    {
        int number;     // numbers = 1, 4, 2, 3, 12
        cin >> number;

        // fetch
        cout << hash[number] << endl;
    }
    return 0;
}

        int hash[n];        // <- here the value of 'n' can go upto 10^6, if it is declared under main()
                            // but if we declare it globally it can go upto 10^8, like below
                            // int hash[1e8];
                            // int main(){}

                            
                        --- Character Hashing ---

                    lets have an array s = "a b c d a b e f c"
        pseudo code
f(char c, s)
{
    cnt = 0
    for(int i = 0; i < n; i++)
    {
        if(s[i] == c)
            cnt++;
    }
    return cnt;
}

                TC - O(q × N)       // <- same as previous

        Actual Code (only for small case letters)
int main()
{
    string s;
    cin >> s;

    // precompute
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;         // s[i] - 'a', will give the indexing(ASCII)
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;

        // fetch
        cout << hash[c - 'a'] << endl;      // c - 'a', character minus index
    }
}

        if it doesn't specify that character is uppercase or lowercase
int main()
{
    string s;
    cin >> s;

    // precompute
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;         // s[i] - 'a', will give the indexing(ASCII)
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;

        // fetch
        cout << hash[c] << endl;      // c - 'a', character minus index
    }
}



                        Number Hashing - we cannot Hash number greater than 10^7(declaring globally)
                                         to an array, to Hash number greater than that(i.e 10^9, 10^12)
                                         so to solve this problem we use 'map' and 'unordered map' 
                                         (from STL) adta structure

                Map - lets first take Map
                        we have an array - arr = {1, 2, 3, 1, 3, 2}

                        we know that- map<key, value>
                                      from the array the numbers are keys and frequency are the value
                                      // frequency- how many times a number appear in the array is frequency

                                      to map the array we have to write as
                                                mpp[arr[i]]++           // it will increment every time same number appears

                                        like from above array, it stores -  1->1 then 2->1 then 3->1 then,
                                                                            1->2 then 3->2 then 2->2
                TC(map) - storing -- log N  (number of elements)
                          fetching - log N

        Actual code  (for inputs-  arr length - 7
                                   arr - 1, 2, 3, 1, 3, 2, 12
                                   query - 5
                                   queries - 1
                                             2
                                             3
                                             4
                                             12)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)      // we can merge map in this loop(will be doing in unordered_map)
    {
        cin >> arr[i];
    }

    // pre-compute
    map<int, int> mpp;              // for character hashing- map<char, int> mpp;
    for(int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // iterate in the map
    for(auto it: mpp)                       // extra, to sort in a manner
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int number;
        cin >> number;

        //fetch
        cout << mpp[number] << endl;
    }
    return 0;
}
        


                Unordered_map  - below code will give us the o/p in unordered manner

                TC -  storing  - O(1)  // <- average and best complexity most of the time
                      fetching - O(1)
                                 // in worst case O(N)


                    Note- we should always use Unordered_map at first, if it gives
                          Time Limit Complexity then we will use Map

        Actual Code
int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    // pre-compute
    // we merge the map with array

    // iterate in the map
    for(auto it: mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int number;
        cin >> number;

        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}
*/



/*
            to store number greater than 10^7, we use the following methods
            only division method is important

      Hashing collision -  1. Dvision method
                           2. Folding method
                           3. Mad square method

            1. Division method - lets take an array- {2, 5, 16, 28, 139} 
                                 and we are taking resctriction of array size 10

                                 to solve this, we just have to get module of the 
                                 array with restriction size
                                                    i.e  arr[i] % 10 (int this case)

                                from the above array we get 2 % 10 = 2
                                                            5 % 10 = 5
                                                            16 % 10 = 6
                                                            28 % 10 = 8
                                                            139 % 10 = 9
                                                            result of the module store in the respective number

                                                            by this placing of module number, we can hashing(know 
                                                            the repeatation of the number)

                                                            if we have the numbers of same modules then the numbers
                                                            will be stored in chained order(in sorted form)
                                                            exa- 18, 28, 28, 38 will be stored in 8 place, in the 
                                                                form of 18->28->28->38
                                                                when we want to find the number of times 28 appear in
                                                                the array we simply go to the 8 place and get the 
                                                                appearance of 28 by binary search

            Collision - when we get an array which gives module of the same number(i.e {2, 22, 42, 52, 62, 82, 52}), then
                        all the modules will be stored in 2 place and none of the other numbers place will be used, and 2 
                        place become crowded, this will cause collision in hashing.

                        
                        Note- solve the two problems from Striver's A2Z DSA sheet

*/

int main()
{
    std::cout << "Hello World!\n";
}