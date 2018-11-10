package Model.Utils;

import java.util.Stack;

public class MyStack<T> implements IStack<T>{
    Stack<T> stack;

    public MyStack(){
        stack = new Stack<T>();
    }

    @Override
    public void push(T elem) {
        //push element in stack
        stack.push(elem);
    }

    @Override
    public T pop() {
        //pop element from stack
        //return the poped elem
        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
        //stack.pick()
    }

    public String toString(){
        String s = "";
        for(T i : stack)
            s += i.toString() + "\n";
        return s;
    }
}
