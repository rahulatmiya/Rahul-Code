package com.rpise;

import java.util.*;

public class LearningCollections {

    public static void main(String[] args) {

        Employee e1 = new Employee("Zoya", 10, 300000);
        Employee e2 = new Employee("Jai", 24, 500000);
        Employee e3 = new Employee("Ayan", 12, 250000);

        ArrayList<Employee> al = new ArrayList<>();
        al.add(e1);
        al.add(e2);
        al.add(e3);

        //Using overridden equals method
        System.out.println(e1.equals(e3));

        //Using Comparable interface 
        System.out.println("\nEmployees comparison by Experience...");
        System.out.println(e2.compareTo(e3));

        //Using Comparator interface
        System.out.println("\nEmployees comparison by Salary...");
        SalaryComparator s = new SalaryComparator();
        System.out.println(s.compare(e1, e2));

        //Sorting by Experience
        System.out.println("\nSorting Employees by Experience...");
        Collections.sort(al, new ExperienceComparator());
        Iterator<Employee> i1 = al.iterator();
        while (i1.hasNext()) {
            Employee next = i1.next();
            System.out.println(next.getExperience());
        }

        //Sorting by Salary
        System.out.println("\nSorting Employees by Salary...");
        Collections.sort(al, new SalaryComparator());
        Iterator<Employee> i2 = al.iterator();
        while (i2.hasNext()) {
            Employee e = i2.next();
            System.out.println(e.getName() + " Salary:" + e.getSalary());
        }

        //Sorting by Names
        System.out.println("\nSorting Employees by Names...");
        Collections.sort(al, new NameComparator());
        Iterator<Employee> i3 = al.iterator();
        while (i3.hasNext()) {
            Employee e = i3.next();
            System.out.println(e.getName());
        }
    }
}


class Employee implements Comparable {
    private int salary;
    private int experience;
    private String name;

    public Employee(String name, int experience, int salary) {
        this.name = name;
        this.experience = experience;
        this.salary = salary;

    }

    public String getName() {
        return name;
    }

    public int getSalary() {
        return salary;
    }

    public int getExperience() {
        return experience;
    }

    @Override
    public boolean equals(Object obj) {
        Employee e = (Employee) obj;
        if (this == obj) {
            System.out.println("Both are same objects...");
            return true;
        }
        if (obj == null) {
            System.out.println("Handle is initialised to null...");
            return false;
        }

        if (this.experience != e.experience) {
            System.out.println("Employess experience is not same...");
            return false;
        }
        System.out.println("Experience is same...");
        return true;
  }

    @Override
    public int compareTo(Object obj) {
        Employee e = (Employee) obj;
        if (this.experience == e.experience) {
            System.out.println(this.name + " and " + e.name + " have same experience");
            return 0;
        }
        if (this.experience > e.experience) {
            int exp = (this.experience) - (e.experience);
            System.out.println(this.name + " has " + exp + " years of more experience than " + e.name);
            return 1;
        }
        System.out.println(this.name + " experience is less than " + e.name);
        return -1;
    }
}


class SalaryComparator implements Comparator<Employee> {

    @Override
    public int compare(Employee e1, Employee e2) {
        if (e1.getSalary() == e2.getSalary()) {
            System.out.println(e1.getName() + " and " + e2.getName() + " salary is equal");
            return 0;
        } else if (e1.getSalary() > e2.getSalary()) {
            System.out.println(e1.getName() + " salary is greater than " + e2.getName());
            return 1;
        } else {
            System.out.println(e1.getName() + " salary is less than " + e2.getName());
            return -1;
        }
    }
}

class ExperienceComparator implements Comparator<Employee> {

    @Override
    public int compare(Employee e1, Employee e2) {

        if (e1.getExperience() == e2.getExperience()) {
            return 0;
        } else if (e1.getExperience() > e2.getExperience()) {
            return 1;
        } else {
            return -1;
        }
    }
}

class NameComparator implements Comparator<Employee> {

    @Override
    public int compare(Employee e1, Employee e2) {

        return e1.getName().compareTo(e2.getName());
    }
}