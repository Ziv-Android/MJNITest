package com.ziv.jni.collection;

/**
 * 复杂类
 *
 * Created by ziv on 17-6-19.
 */

public class Human {
    private String name = "Aling";
    private int age = 23;
    private Teacher teacher;
    private Worker worker;

    public class Teacher {
        String subject = "Chinese";
    }
    public class Worker {
        String type = "coder";
    }

    @Override
    public String toString() {
        return "Human{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", teacher=" + teacher.subject +
                ", worker=" + worker.type +
                '}';
    }
}
