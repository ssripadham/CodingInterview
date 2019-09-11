/* 
A vending machine serves three options: "Snack", "Drink" or "Surprise Me". 
The machine dispenses the oldest item first (e.g. worker refills machine each day, 
one at a time, and the machine serves items first in, first out). 
Implement data structure to maintain inventory: implement enqueue(), dequeueAny(), dequeueDrink(), 
and dequeueSnack().
*/

#include <queue>
#include <iostream>
#include <utility>

using namespace std;

#define SNACK 1
#define DRINK 2

class Item {
   int type;
};

typedef pair<int, Item> STOCK;

class pop_machine {

    private:
        queue<STOCK> snackQueue;
        queue<STOCK> drinkQueue;
        
        int itemId;
 
        
    public:
        
        pop_machine(): itemId(0) { };
        
        ~pop_machine() { } ;    
        
        void enqueue(Item item) {
            (i.type == SNACK) ? snackQueue.push(make_pair(itemId++,item)) : drinkQueue.push(make_pair(itemId++,item));
        };
        
        Item dequeueSnack(){
            if (isSnackEmpty()) {
                //throw exception here
                return NullItem;
            }
            
            STOCK ret = snackQueue.front();
            snackQueue.pop();
          
            return ret.second;
        };
        
        Item dequeueDrink(){
            if  (isDrinkEmpty()) {
                //throw exception here
                return NullItem;
            }
            
            STOCK ret = drinkQueue.front();
            drinkQueue.pop();
          
            return ret.second;
        };
        
        Item dequeueAny() {
        
            if (drinkQueue.empty() && snackQueue.empty()) return NullItemm;
            
            if (drinkQueue.empty()) return dequeSnack();
            
            //Else both queues have items in them
            
            const STOCK & drink = drinkQueue.front();
            const STOCK & snack = snackQueue.front();
            
            return (snack.first < drink.first) ? dequeSnack() : dequeueDrink();       
        };
        
        bool isSnackEmpty() const { return snackQueue.empty(); }
        bool isDrinkEmpty() const { return drinkQueue.empty(); }
 }