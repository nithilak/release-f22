/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{
    // Your code here
    if (s.size() <= 1) {
        return s.top();
    } else {
        T& top = s.top();
        s.pop();
        T sum2 = sum(s);
        s.push(top);
        return top + sum2;
    }
    return T(); // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
    //count all left brackets
    //count all right brackets
    //return if both counts are the same
    //this is not a correct implementation
    
    //create a stack
    //push issues to be closed onto the stack
    //do nothing if the char is not a left or right bracket
    //open issues each time you see an opening bracket
    //close the last issue each time you see a closing bracket
    //move on to the next char
    //return if the stack is empty

    std::stack<int> stack;

    while (!input.empty()) {
        char front = input.front();
        input.pop();
        if (front == '[') {
            stack.push(1);
        } else if (front == ']') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }

    // // @TODO: Make less optimistic
    // return true;
    return stack.empty();
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    // optional: queue<T> q2;

    // Your code here
    int items_left_in_q = q.size();
    int count = 1;
    for (; items_left_in_q > count; count++) {
        std::cout << "count" << count << std::endl;
        std::cout << "items_left_in_q" << items_left_in_q << std::endl;
        std::cout << "(count % 2 == 0)" << (count % 2 == 0) << std::endl;
        if (count % 2 == 0) {
            for (int j = 0; j < count; j++) {
                s.push(q.front());
                q.pop();
                items_left_in_q--;
            }
            std::cout << "s.size()" << s.size() << std::endl;
            while (!s.empty()) {
                std::cout << "s.top()" << s.top() << std::endl;
                q.push(s.top());
                s.pop();
            }
        } else {
            for (int k = 0; k < count; k++) {
                q.push(q.front());
                q.pop();
                items_left_in_q--;
            }
        }
        std::cout << "items_left_in_q" << items_left_in_q << std::endl;
    }
    if (count % 2 == 0) {
        while (items_left_in_q > 0) {
            s.push(q.front());
            q.pop();
            items_left_in_q--;
        }
        std::cout << "s.size()" << s.size() << std::endl;
        while (!s.empty()) {
            std::cout << "s.top()" << s.top() << std::endl;
            q.push(s.top());
            s.pop();
        }
    } else {
        while (items_left_in_q > 0) {
            q.push(q.front());
            q.pop();
            items_left_in_q--;
        }
    }

}
}
