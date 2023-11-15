package ColorSystem;

public class RGB {
    private int red, green, blue;
    public RGB(int red, int green, int blue){
        this.red = Math.max(Math.min(red, 255), 0);
        this.green = Math.max(Math.min(green, 255), 0);
        this.blue = Math.max(Math.min(blue, 255), 0);
    }

    public int getRed() {
        return red;
    }

    public int getGreen() {
        return green;
    }

    public int getBlue() {
        return blue;
    }

    public void setRed(int red) {
        this.red = Math.max(Math.min(red, 255), 0);
    }

    public void setGreen(int green) {
        this.green = Math.max(Math.min(green, 255), 0);
    }

    public void setBlue(int blue) {
        this.blue = Math.max(Math.min(blue, 255), 0);
    }

    @Override
    public String toString() {
        return "RGB[" + red + "," + green + "," + blue + ']';
    }
}