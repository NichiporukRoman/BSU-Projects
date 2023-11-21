package ColorSystem;

public class CMYK {
    private int cyan, magenta, yellow, key;
    public CMYK( int cyan, int magenta, int yellow, int key){
        this.cyan = Math.max(Math.min(cyan, 100), 0);
        this.magenta = Math.max(Math.min(magenta, 100), 0);
        this.yellow = Math.max(Math.min(yellow, 100), 0);
        this.key = Math.max(Math.min(key, 100), 0);
    }

    public int getCyan() {
        return cyan;
    }

    public int getMagenta() {
        return magenta;
    }

    public int getYellow() {
        return yellow;
    }

    public int getKey() {
        return key;
    }

    public void setCyan(int cyan) {
        this.cyan = Math.max(Math.min(cyan, 100), 0);
    }

    public void setMagenta(int magenta) {
        this.magenta = Math.max(Math.min(magenta, 100), 0);
    }

    public void setYellow(int yellow) {
        this.yellow = Math.max(Math.min(yellow, 100), 0);
    }

    public void setKey(int key) {
        this.key = Math.max(Math.min(key, 100), 0);
    }

    @Override
    public String toString() {
        return "CMYK[" + cyan + "," + magenta + "," + yellow + "," + key + ']';
    }
}