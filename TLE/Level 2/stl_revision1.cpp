// no of operation in 1second=10^8
// int=-1e9 to 1e9
// long long -1e18 to 1e18
// unsigned long long =0 to 2*1e18
// mod arithmatic for >1e18

// "\n" faster than endl

// vector<int>vec           = push_back() can be done
// vector<int>vec(n,0)      = push_back() cannot be done

// emplace_back() faster then push_back()


// set:-
       // store unique element in sorted order
       // set<int>st;
       // st.erase(value)           // log(n)
       // auto it=st.begin()
       // stores in contingous manner
       // insert              // log(n)
       // st.size()           //give size
       // st.find(value)      // give iterator to value
       // st.erase(it,it+4);  // give wrong
       // correct:-
                 // auto jt=it
                 // for(int i=0;i<4;i++){
                 //    jt++;
                 // }
                 // st.erase(it,jt)  // now correct
                 // 
       // st.clear()            // O(nlogn)
       
// unordered_set:-
       // unorderd_set<int>st;
       // constant time,unique element,any order
       // TC=O(1) of all the operations
       // st.clear()       // O(n)

// try using set

// multiset:-
        // multiset<int>mst;
        // not unique,sorted order
        // mst.count(1);
        // mst.erase(1);                // erase all 1 present in mst
        // mst.erase(mst.find(1));      // erase only one 1 in mst
        // mst.clear()                  // O(nlogn)

// map:-
        // map<int,int>mp
        // unique keys and sorted in order in keys
        // auto it=mp.find(12)     // return pair of {key,value}
        // mp.erase(mp.find(12))
        // 