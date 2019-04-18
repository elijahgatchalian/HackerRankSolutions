//
//  Eli Gatchalian
//  HackerRankSolutions
//
//  Copyright © 2019 Eli Gatchalian. All rights reserved.
//
//
//   Hi everyone! I'm a software engineer and I decided to compile my solutions to
//   some of the problems posted on leetcode.com using C++. I have provided time
//   and space complexity for each problem. Feel free to message me if you see something
//   confusing or wrong!
//

// Definition for singly-linked list.
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

//
//  Simple Array Sum - Easy
//
//  Given an array of integers, find the sum of its elements.
//  For example, if the array ar = [1,2,3], 1 + 2 + 3 = 6, so return 6.
//
//  Big(O) -> O(n), where n = size of the array
//  Memory -> O(1)
//

int simpleArraySum(vector<int> ar){
    //  Purpose: Take the sum of the entire array
    //  Input: A vector of integers
    //  Output: An integer of the summation of values in the array
    int sum = 0;
    for(int i = 0; i < ar.size(); i++){
        sum += ar[i];
    }
    return sum;
}

//
//  Diagonal Difference - Easy
//
//  Given a square matrix, calculate the absolute difference between the sum of its diagonals.
//
//  For example, the square matrix arr is shown below:
//
//  123
//  456
//  989
//
//  The left-to-right diagonal = 1 + 5 + 9 = 15. The right to left diagonal = 3 + 5 + 9 = 17.
//  Their absolute difference is |15 - 17| = 2.
//
//  Big(O) -> O(r), where r = how many rows are in the 2D array
//  Memory -> O(1)
//

int diagonalDifference(vector<vector<int>> arr) {
    //  Purpose: Find the absolute diagonal difference of the 2D vector
    //  Input: A 2D-Array of integers
    //  Output: An integer of the difference between the diagonal summation
    int leftToRightDiagonal = 0, rightToLeftDiagonal = 0;
    int size = (int)arr.size();
    
    //  Take the summation of both diagonals while walking through the array once
    for(int i = 0; i < size; i++){
        leftToRightDiagonal += arr[i][i];
        rightToLeftDiagonal += arr[size - 1 - i][i];
    }
    
    return abs(leftToRightDiagonal - rightToLeftDiagonal);
}

//
//  Climbing the Leaderboard - Medium
//
//  Alice is playing an arcade game and wants to climb to the top of the leaderboard and wants to
//  track her ranking. The game uses Dense Ranking, so its leaderboard works like this:
//
//  - The player with the highest scores is ranked number 1 on the leaderboard.
//  - Players who have equal scores receive the same ranking number, and the next player(s) receive
//  the immediately following ranking number.
//
//  For example, the four players on the leaderboard have high scores 100, 90, 90, and 80. Those
//  players will have ranks 1, 2, 2, and 3 respectively. If Alice's scores are 70, 80, and 105,
//  her rankings after each game are 4th, 3rd, and 1st.
//
//  Big(O) -> O(max(s,a)), where s and a = the sizes of the 'scores' and 'alice' arrays
//  Memory -> O(max(s,a)), where s and a = the sizes of the 'scores' and 'alice' arrays
//

void createUniqueScores(vector<int> &uniqueScores, const vector<int> scores){
    //  Purpose: Find all unique scores in 'scores'
    //  Input:
    //      - uniqueScores: an empty vector
    //      - scores: a sorted vector of integers from greatest to least
    //  Output: No output but changes uniqueScores to have unique values from the scores vector
    int prevNum = -1;
    for(int i = (int)scores.size() - 1; i >= 0; i--){
        if(scores[i] != prevNum){
            uniqueScores.push_back(scores[i]);
            prevNum = scores[i];
        }
    }
}

vector<int> aliceRanks(const vector<int> uniqueScores, const vector<int> alice){
    //  Purpose: Calculate alice's score ranks after each game
    //  Input:
    //      - uniqueScores: unique integers
    //      - alice: a sorted vector of integers from least to greatest
    //  Output: Outputs a vector of alice's ranking after each of her games
    vector<int> ranks;
    int maxRank = (int)uniqueScores.size(), j = 0;
    for(int i = 0; i < alice.size(); i++){
        while(j < maxRank && alice[i] > uniqueScores[j]) j++;
        int currentRank = maxRank - j;
        if(alice[i] != uniqueScores[j]) currentRank++;
        ranks.push_back(currentRank);
    }
    return ranks;
}

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    //  Purpose: Figure out alice's rank after each game
    //  Input:
    //      - scores: A vector of integers of the current leaderboard
    //      - alice: A vector of integers of alice's scores
    //  Output: A vector of integers of alice's ranking after each of her game
    vector<int> uniqueScores;
    createUniqueScores(uniqueScores, scores);
    return aliceRanks(uniqueScores, alice);
}

//
//  Equalize the Array - Easy
//
//  Karl has an array of integers. He wants to reduce the array until all remaining elements
//  are equal. Determine the minimum number of elements to delete to reach his goal.
//
//  For example, if his array is arr = [1,2,2,3], we see that he can delete the 2 elements 1 and 3
//  leaving arr = [2,2]. He could also delete both twos and either the 1 or the 3, but that would
//  take 3 deletions. The minimum number of deletions is 2.
//
//  Big(O) -> O(n), where n = size of the array
//  Memory -> O(n), where n = size of the array
//

int equalizeArray(vector<int> arr) {
    //  Purpose: Equalize the array
    //  Input: A vector of integers
    //  Output: An integer of the minimum amount of deletions it would take to equalize the array
    int maxOccurence = 0, size = (int)arr.size();
    unordered_map<int,int> numToOccurence;
    
    for(int i = 0; i < size; i++){
        numToOccurence[arr[i]]++;
        if(numToOccurence[arr[i]] > maxOccurence) maxOccurence = numToOccurence[arr[i]];
    }
    
    return size - maxOccurence;
}

//
//  Counting Valleys - Easy
//
//  Gary is an avid hiker. He tracks his hikes meticulously, paying close attention to small
//  details like topography. During his last hike he took exactly n steps. For every step he
//  took, he noted if it was uphill, U, or a downhill, D step. Gary's hike starts and end at
//  sea level and each step up or down represents a 1 unit change in altitude. We define
//  the following terms:
//
//  - A mountain is a sequence of consecutive steps above sea level, starting with a step up from
//  sea level and ending with a step down to sea level.
//  - A valley is a sequence of consecutive steps below sea level, starting with a step down from
//  sea level and ending with a step up to sea level.
//
//  Given Gary's sequence of up and down steps during his last hike, find and print the number of
//  valleys he walked through.
//
//  For example, if Gary's path is s = [DDUUUDD], he first enters a valley 2 units deep. Then he
//  climbs out an up onto a mountain 2 units high. Finally, he returns to sea level and ends his
//  hike.
//
//  Big(O) -> O(n), where n = the amount of steps taken/size of the string
//  Memory -> O(1)
//

int countingValleys(int n, string s) {
    //  Purpose: Count the valleys in the input string
    //  Input:
    //      - n: An integer of how long the input string is
    //      - s: A string of Ds and Us representing uphill/downhill steps
    //  Output: An integer representing how many valleys have been hiked
    int altitude = 0, valleys = 0;
    
    for(int step = 0; step < s.length(); step++){
        if(s[step] == 'U') altitude++;
        else altitude--;
        
        if(altitude == 0 && s[step] == 'U') valleys++;
    }
    
    return valleys;
}

//
//  Pairs - Medium
//
//  You will be given an array of integers and a target value. Determine the number of pairs
//  of array elements that have a difference equal to a target value.
//
//  For example, given an array of [1,2,3,4] and a target value of 1, we have three values
//  meeting the condition: 2 - 1 = 1, 3 - 2 = 1, and 4 - 3 = 1.
//
//  Big(O) -> O(n), where n = size of the array
//  Memory -> O(n), where n = size of the array
//

int pairs(int k, vector<int> arr) {
    //  Purpose: Find the amount of pairs that sum up to the target value
    //  Input:
    //      - k: An integer representing the target value
    //      - arr: A vector of integers
    //  Output: An integer of how many different pairs are present in the vector that add up
    //          to the target value
    int numPairs = 0;
    unordered_map<int,int> numbers;
    
    for(int i = 0; i < arr.size(); i++){
        if(numbers.find(arr[i]) == numbers.end()) numbers[arr[i]] = 1;
        else return -1; // invalid entry
    }
    
    for(int i = 0; i < arr.size(); i++){
        int target = arr[i] + k;
        auto it = numbers.find(target);
        if(it != numbers.end() && it->first != arr[i]) numPairs++;
    }
    
    return numPairs;
}

//
//  Connected Cells in a Grid - Medium
//
//  Consider a matrix where each cell contains either a 0 or a 1. Any cell containing a 1 is called
//  a filled cell. Two cells are said to be connected if they are adjacent to each other
//  horizontally, vertically, or diagonally. In the following grid, all cells marked X are
//  connected to the cell marked Y.
//
//  XXX
//  XYX
//  XXX
//
//  If one or more filled cells are also connected, they form a region. Note that each cell in a
//  region is connected to zero or more cells in the region but is not necessarily directly
//  connected to all the other cells in the region.
//
//  Given an n x m matrix, find and print the number of cells in the largest region in the matrix.
//  Note that there may be more than one region in the matrix.
//
//  For example, there are two regions in the following 3 x 3 matrix. The larger region at the top
//  left contains 3 cells. The smaller one at the bottom right contains 1.
//
//  110
//  100
//  001
//
//  Big(O) -> O((n + m)^2), where n and m are the dimensions of the matrix
//  Memory -> O(1)
//

bool valid(const vector<vector<int>> matrix, const int x, const int y){
    //  Purpose: Validate the coordinates in the grid
    //  Input:
    //      - matrix: A 2D vector of integers representing a grid
    //      - x: An integer representing an x-coordinate in the grid
    //      - y: An integer representing a y-coordinate in the grid
    //  Output: A boolean whether or not the place in the grid is valid
    return (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] == 1);
}

void findRegions(vector<vector<int>> &matrix, const int x, const int y, int &regionSize){
    //  Purpose: Calculate the sizes of each region in the grid
    //  Input:
    //      - matrix: A 2D vector of integers representing a grid
    //      - x: An integer representing an x-coordinate in the grid
    //      - y: An integer representing a y-coordinate in the grid
    //      - regionSize: An integer representing the current region's size
    //  Output: No output, but this function changes the following variables via pass-by-reference
    //      - matrix: If the x,y position is 1, change it to 0
    //      - regionSize: If the x,y position is 1, increment the region size
    if(!valid(matrix, x, y)) return;
    
    regionSize++;
    
    matrix[x][y] = 0; //    Make sure not to revisit this coordinate again
    
    //  Starting from -1 to 1 to search the surrounding area of the x,y coordinate
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            findRegions(matrix, x + i, y + j, regionSize);
        }
    }
}

int connectedCell(vector<vector<int>> matrix){
    //  Purpose: Find the largest region in the grid
    //  Input: A 2D vector of integers representing a grid
    //  Output: An integer representing the largest region found in the input vector
    int maxRegion = 0;
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            int currentRegion = 0;
            findRegions(matrix, i, j, currentRegion);
            if(currentRegion > maxRegion) maxRegion = currentRegion;
        }
    }
    
    return maxRegion;
}

//
//  Minimum Absolute Difference in an Array - Easy
//
//  Consider an array of integers, arr = [arr[0], arr[1],..., arr[n - 1]]. We define the absolute
//  difference between two elements, a[i] and a[j] (where i != j), to be the absolute value of
//  a[i] - a[j].
//
//  Given an array of integers, find and print the minimum absolute difference between any two
//  elements in the array. For example, given the array arr = [-2,2,4] we can create 3 pairs of
//  numbers: [-2,2], [-2,4] and [2,4]. The absolute differences for these pairs are |(-2) - 2| = 4,
//  |(-2) - 4| = 6 and |2 - 4| = 2. The minimum absolute difference is 2.
//
//  Big(O) -> O(nlogn), where n = the size of the array
//  Memory -> O(1)
//

int minimumAbsoluteDifference(vector<int> arr){
    //  Purpose: Find the minimum absolute difference between the values in the input vector
    //  Input: An array of integers
    //  Output: An integer representing the minimum difference between values in the input vector
    sort(arr.begin(), arr.end());
    int minimumDifference = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++){
        if(abs(arr[i] - arr[i + 1]) < minimumDifference){
            minimumDifference = abs(arr[i] - arr[i + 1]);
        }
    }
    
    return minimumDifference;
}

//
//  Sparse Arrays - Medium
//
//  There is a collection of input strings and a collection of query strings. For each query
//  string, determine how many times it occurs in the list of input strings.
//
//  For example, given input strings = ['ab', 'ab', 'abc'] and queries = ['ab', 'abc', 'bc'],
//  we find 2 instances of 'ab', 1 of 'abc' and 0 of 'bc'. For each query, we add an element
//  to our return array results, results = [2,1,0].
//
//  Big(O) -> O(max(s,q)), where s and q are the sizes of the 'strings' and 'queries' arrays
//  Memory -> O(s), where s is the size of the 'strings' array
//

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    //  Purpose: Find how many times a value in queries appear in strings
    //  Input:
    //      - strings: A vector of strings. There can be duplicate values in here.
    //      - queries: A vector of strings. No duplicate values.
    //  Output: A vector of integers of how many times a value in queries appear in strings
    unordered_map<string,int> words;
    //  Find how many times a given word appears in string using a hash map
    for(int i = 0; i < strings.size(); i++){
        words[strings[i]]++;
    }
    
    vector<int> results;
    //  Walk through queries vector and look it up in the hash map
    //  Push the value from the hash map into the results array
    for(int i = 0; i < queries.size(); i++){
        results.push_back(words[queries[i]]); // If queries[i] is not in words, it will simply return a 0
    }
    
    return results;
}

//
//  Cycle Detection - Medium
//
//  A linked list is said to contain a cycle if any node is visted more than once while
//  traversing the list.
//
//  Complete the function provided for you in your editor. It has one parameter: a pointer
//  to a Node object named head that points to the head of a linked list. Your function must
//  return a boolean denoting whether or not there is a cycle in the list. If there is a cycle,
//  return true; otherwise, return false.
//
//  Note: If the list is empty, head will be null.
//
//  Big(O) -> O(n), where n = size of the linked list
//  Memory -> O(n), where n = size of the linked list
//

bool has_cycle(SinglyLinkedListNode* head) {
    //  Purpose: Identify if the singly linked list is circular
    //  Input: A singly linked list
    //  Output: A boolean representing whether or not the list is circular
    SinglyLinkedListNode *slow, *fast;
    slow = head;
    fast = head;
    
    //  Imagine two racers on a track field. If they are running endlessly in a circle, the fast runner will
    //  run past the slow runner, at which point their positions are the same. If this is a 100m
    //  race, the fast runner will reach the end before the slow runner, meaning this is not circular.
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    
    return false;
}

//
//  Balanced Brackets - Medium
//
//  A bracket is considered to be any of the following characters: (, ), {, }, [, or ].
//
//  Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {)
//  occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are
//  three types of matched pairs of brackets: [], {}, and ().
//
//  A matching pair of brackets is not balanced if the set of brackets it encloses are not matched.
//  For example, {[(])} is not balanced because the contents in between { and } are not balanced.
//  The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of
//  parentheses encloses a single, unbalanced closing square bracket, ].
//
//  By this logic, we say a sequence of brackets is balanced if the following conditions are met:
//  - It contains no unmatched brackets.
//  - The subset of brackets enclosed within the confines of a matched pair of brackets is also a
//  matched pair of brackets.
//
//  Given n strings of brackets, determine whether each sequence of brackets is balanced. If a
//  string is balanced, return YES. Otherwise, return NO.
//
//  Big(O) -> O(n), where n = length of the string 's'
//  Memory -> O(n), where n = length of the string 's'
//

bool match(char leftBracket, char rightBracket){
    //  Purpose: Validate if the brackets complete each other
    //  Input:
    //      - leftBracket: A character representing (, {, or [
    //      - rightBracket: A character representing ), }, or ]
    //  Output: A boolean returning if the left and right bracket match
    if(leftBracket == '(' && rightBracket != ')') return false;
    else if(leftBracket == '{' && rightBracket != '}') return false;
    else if(leftBracket == '[' && rightBracket != ']') return false;
    else return true;
}

string isBalanced(string s) {
    //  Purpose: Identify if the input string has all matching brackets
    //  Input: A string consisting of (,{,[,],}, and )
    //  Output: A YES/NO message representing that all brackets have succesfully closed
    stack<char> leftBrackets; //    A stack of characters for (,{,[
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') leftBrackets.push(s[i]);
        else{
            if(leftBrackets.empty() || !match(leftBrackets.top(), s[i])) return "NO";
            leftBrackets.pop();
        }
    }
    
    if(leftBrackets.empty()) return "YES";
    else return "NO";
}

//
//  Find the Running Median - Hard
//
//  The median of a set of integers is the midpoint value of the data set for which an equal number
//  of integers are less than and greater than the value. To find the median, you must first sort
//  your set of integers in non-decreasing order, then:
//
//  - If your set contains an odd number of elements, the median is the middle element of the
//  sorted sample. In the sorted set {1,2,3}, 2 is the median.
//  - If your set contains an even number of elements, the median is the average of the two middle
//  elements of the sorted sample. In the sorted set {1,2,3,4}, (2+3)/2 = 2.5 is the median.
//
//  Given an input stream of n integers, you must perform the following task for each ith integer:
//  1. Add the ith integer to a running list of integers.
//  2. Find the median of the updated list (i.e., for the first element through the ith element).
//  3. Print the list's updated median on a new line. The printed value must be a double-precision
//  number scaled to 1 decimal place (i.e., 12.3 format).
//
//  Big(O) -> O(nlogn), where n = size of the array
//  Memory -> O(n), where n = size of the array
//

void addToHeaps(const double currentNum, const double median, priority_queue<double> &maxHeap, priority_queue<double, vector<double>, greater<double>> &minHeap){
    //  Purpose: Push the current number onto the appropriate heap
    //  Input:
    //      - currentNum: A double representing the current number
    //      - median: A double representing the median value
    //      - maxHeap: A max heap of double values
    //      - minHeap: A min heap of double values
    //  Output: No output but pushes currentNum onto either maxHeap or minHeap depeneding on
    //          if the currentNum is less than or equal to the median
    if(currentNum <= median) maxHeap.push(currentNum);
    else minHeap.push(currentNum);
}
void changeHeapSizes(priority_queue<double> &maxHeap, priority_queue<double, vector<double>, greater<double>> &minHeap){
    //  Purpose: Change the heap size so that no heap is larger than the other by 2
    //  Input:
    //      - maxHeap: A max heap of double values
    //      - minHeap: A min heap of double values
    //  Output: No output but pushes the top value from one heap to the other heap depending on
    //          the sizes of the heaps. Either heap should not be greater than 2. Once this has been done,
    //          the top value is popped off the heap.
    if(maxHeap.size() > minHeap.size() + 1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }else if(minHeap.size() > maxHeap.size() + 1){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

vector<double> runningMedian(vector<int> a) {
    //  Purpose: Find the running median as we walk through the input vector
    //  Input: A vector of integers
    //  Output: A vector of doubles of all median values
    priority_queue<double, vector<double>, greater<double>> minHeap;
    priority_queue<double> maxHeap;
    vector<double> allMedians;
    double currentMedian = 0;
    
    for(int i = 0; i < a.size(); i++){
        addToHeaps((double) a[i], currentMedian, maxHeap, minHeap);
        changeHeapSizes(maxHeap, minHeap);
        
        //  Calculate current median
        if(minHeap.size() == maxHeap.size()) currentMedian = (minHeap.top() + maxHeap.top())/2;
        else if(minHeap.size() > maxHeap.size()) currentMedian = minHeap.top();
        else currentMedian = maxHeap.top();
        
        //  Push current median into vector
        allMedians.push_back(currentMedian);
    }
    
    return allMedians;
}

//
//  Snakes and Ladders: The Quickest Way Up - Medium
//
//  Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always
//  roll the die to whatever number I want, what would be the least number of rolls to reach the
//  destination?"
//
//  Rules The game is played with a cubic die of 6 faces numbered 1 to 6.
//
//  1. Starting from square 1, land on square 100 with the exact roll of the die. If moving the
//  number rolled would place the player beyond square 100, no move is made.
//  2. If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up
//  only.
//  3. If a player lands at the mouth of a snake, the player must go down the snake and come out
//  through the tail. Snakes go down only.
//
//  Big(O) -> O(max(max(100,l),s)), where l and s are the sizes of ladders and snakes
//  Memory -> O(1), the game board will never exceed a size of 100
//

void setupBoard(vector<int> &board, const vector<vector<int>> ladders, const vector<vector<int>> snakes){
    //  Purpose: Create the game board based on the ladders and snakes 2D vectors
    //  Input:
    //      - board: An empty vector of integers representing the game board
    //      - ladders: A 2D vector of integers representing where to move to if a ladder has been reached
    //      - snakes: A 2D vector of integers representing where to move to if a snake has been reached
    //  Output: No output but creates the game board via pass-by-reference
    for(int i = 0; i < 100; i++){
        board[i] = i;
    }
    for(int i = 0; i < ladders.size(); i++){
        board[ladders[i][0] - 1] = ladders[i][1] - 1;
    }
    for(int i = 0; i < snakes.size(); i++){
        board[snakes[i][0] - 1] = snakes[i][1] - 1;
    }
}

int moveThroughBoard(vector<int> distanceToGetToIndex, const vector<int> board){
    //  Purpose: Move through the board until we reach the game
    //  Input:
    //      - distanceToGetToIndex: A vector of integers on the distance it took to reach
    //                              the current index
    //      - board: A vector of integers representing the game board
    //  Output: An integer of the distance it took to reach the end of the game board. Returns
    //          -1 if not possible.
    queue<int> positions;
    positions.push(0);
    
    while(!positions.empty()){
        int currentPos = positions.front();
        positions.pop();
        for(int i = currentPos + 1; i <= currentPos + 6; i++){
            if(distanceToGetToIndex[board[i]] == 0){
                positions.push(board[i]);
                distanceToGetToIndex[board[i]] = distanceToGetToIndex[currentPos] + 1;
                if(board[i] == 99) return distanceToGetToIndex[board[i]];
            }
        }
    }
    
    return -1;
}

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    //  Purpose: Find the quickest way to complete the game
    //  Input:
    //      - ladders: A 2D vector of integers of the beginning and end positions
    //                 of the ladder
    //      - snakes: A 2D vector of integers of the beginning and end positions
    //                of the snake
    //  Output: An integer of the quickest way to reach the end of the game board
    vector<int> distanceToGetToIndex(100), board(100);
    
    setupBoard(board, ladders, snakes);
    int shortestDistance = moveThroughBoard(distanceToGetToIndex, board);
    
    return shortestDistance;
}
