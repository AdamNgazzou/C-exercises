int findDuplicate(int* nums, int numsSize) {
    // Phase 1: Detect the cycle using Floyd's Tortoise and Hare
    int slow = nums[0];
    int fast = nums[0];
    
    // Move slow by 1 step and fast by 2 steps until they meet
    do {
        slow = nums[slow];        
        fast = nums[nums[fast]];  
    } while (slow != fast);      

    // Phase 2: Find the entry point of the cycle (the duplicate number)
    slow = nums[0]; // reset slow to the start
    while (slow != fast) {
        slow = nums[slow]; 
        fast = nums[fast];  
    }

    return slow;
}
