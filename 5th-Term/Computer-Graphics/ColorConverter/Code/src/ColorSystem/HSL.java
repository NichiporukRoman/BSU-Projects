package ColorSystem;

public class HSL {
    private int hue;
    private double saturation, lightness;
    public HSL(int hue, double saturation, double lightness){
        this.hue = Math.max(Math.min(hue, 360), 0);
        this.saturation = Math.max(Math.min(saturation, 100), 0);
        this.lightness = Math.max(Math.min(lightness, 100), 0);
    }

    public int getHue() {
        return hue;
    }

    public double getSaturation() {
        return saturation;
    }

    public double getLightness() {
        return lightness;
    }

    public void setHue(int hue) {
        this.hue = Math.max(Math.min(hue, 360), 0);
    }

    public void setSaturation(double saturation) {
        this.saturation = Math.max(Math.min(saturation, 100), 0);
    }

    public void setLightness(double lightness) {
        this.lightness = Math.max(Math.min(lightness, 100), 0);
    }

    @Override
    public String toString() {
        return "HSL[" + hue + "," + saturation + "," + lightness + ']';
    }
}