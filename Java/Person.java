public class Person{
    
    private String name;
    private int age;

    public Person(String n, int a){
        this.name = n;
        this.age=a;
    }

    public String toString(){
        return "NAME: " + this.name + " AGE:" + this.age;
    }

    public void setAge(int n){
        if  (n <0){
            //this line is a comment, we wnat to finish the method and no modify age
            return;
        }
        this.age = n;
    }

  

}