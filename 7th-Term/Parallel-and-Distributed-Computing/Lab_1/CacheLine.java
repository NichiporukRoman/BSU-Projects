import java.util.ArrayList;

public class CacheLine{
    
    private int time;
    private ArrayList<Integer> line;
    private int num;

    public CacheLine(int num, int size){
        this.time = 0;
        this.line = new ArrayList<>();
        { for (int i = 0; i < size; i++) line.add(-1);}
        this.num = num;
    }

    public void addTime() {
        this.time++;
    }

    public void resetTime() {
        this.time = 0;
    }

    public int getTime() {
        return time;
    }
    
    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }


    public ArrayList<Integer> getLine() {
        return line;
    }

}