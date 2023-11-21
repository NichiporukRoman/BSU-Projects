import ColorSystem.CMYK;
import ColorSystem.HSL;
import ColorSystem.RGB;

public class СonversionOperations {
    static public CMYK rgb2Cmyk(RGB rgb) {
        double percentageR = rgb.getRed() / 255.0 * 100;
        double percentageB = rgb.getBlue() / 255.0 * 100;
        double percentageG = rgb.getGreen() / 255.0 * 100;

        double k = 100 - Math.max(Math.max(percentageR, percentageG), percentageB);

        if (k == 100) return new CMYK(0,0,0,100);

        int c = (int)((100 - percentageR - k) / (100 - k) * 100);
        int m = (int)((100 - percentageG - k) / (100 - k) * 100);
        int y = (int)((100 - percentageB - k) / (100 - k) * 100);

        return new CMYK(c, m, y, (int)k);
    }
    static public RGB cmyk2Rgb(CMYK cmyk) {
        int red = (int) Math.round ((255 * (1- (float) cmyk.getKey() /100) * (1- (float) cmyk.getCyan() /100)));
        int green = (int) Math.round ((255 * (1- (float) cmyk.getKey() /100) * (1- (float) cmyk.getMagenta() /100)));
        int blue = (int) Math.round  ((255 * (1- (float) cmyk.getKey() /100) * (1- (float) cmyk.getYellow() /100)));
        return new RGB(red, green, blue);
    }

    public static HSL rgb2Hsl(RGB rgb) {
        float h, s, l;
        float r0 = rgb.getRed() / 255.0f;
        float g0 = rgb.getGreen() / 255.0f;
        float b0 = rgb.getBlue() / 255.0f;
        int max = Math.max(rgb.getRed(), Math.max(rgb.getGreen(), rgb.getBlue()));
        int min = Math.min(rgb.getRed(), Math.min(rgb.getGreen(), rgb.getBlue()));
        int d = max - min;
        if (d == 0) {
            h = 0.0f;
            s = 0.0f;
            l = (max + min) * 100.0f / 2.0f / 255.0f;
        } else {
            l = (max + min) / 2.0f / 255.0f;
            float d0 = d / 255.0f;
            s = 100.0f * d0 / (1.0f - Math.abs(2 * l - 1.0f));
            if (max == rgb.getRed()) {
                h = 60.0f * (g0 - b0) / d0;
            } else if (max == rgb.getGreen()) {
                h = 60.0f * ((b0 - r0) / d0 + 2.0f);
            } else {
                h = 60.0f * ((r0 - g0) / d0 + 4.0f);
            }
            if (h < 0) h += 360.0f;
            l *= 100.0f;
        }
        return new HSL((int)h,s,l);
    }
    public static RGB hsl2Rgb(HSL hsl){
        float r = 0, g = 0, b = 0;
        if (hsl.getSaturation() == 0)
        {
            // gray values
            r = g = b = (int) ( hsl.getLightness() * 255 );
        }
        else
        {
            double v1, v2;
            double h = (float) hsl.getHue() / 360;

            v2 = ( hsl.getLightness()/100 < 0.5 ) ?
                    ( hsl.getLightness()/100 * ( 1 + hsl.getSaturation()/100 ) ) :
                    ( ( hsl.getLightness()/100 + hsl.getSaturation()/100 ) - ( hsl.getLightness()/100 * hsl.getSaturation()/100 ) );
            v1 = 2 * hsl.getLightness()/100 - v2;

            r = (int) ( 255 * Hue_2_RGB( v1, v2, h + ( 1.0f / 3 ) ) );
            g = (int) ( 255 * Hue_2_RGB( v1, v2, h ) );
            b = (int) ( 255 * Hue_2_RGB( v1, v2, h - ( 1.0f / 3 ) ) );
        }

        return new RGB((int) r, (int) g, (int) b);
    }
    private static double Hue_2_RGB( double v1, double v2, double vH ){
        if ( vH < 0 )
            vH += 1;
        if ( vH > 1 )
            vH -= 1;
        if ( ( 6 * vH ) < 1 )
            return ( v1 + ( v2 - v1 ) * 6 * vH );
        if ( ( 2 * vH ) < 1 )
            return v2;
        if ( ( 3 * vH ) < 2 )
            return ( v1 + ( v2 - v1 ) * ( ( 2.0f / 3 ) - vH ) * 6 );
        return v1;
    }

    public static HSL cmyk2Hsl(CMYK cmyk){
        return rgb2Hsl(cmyk2Rgb(cmyk));
    }

    public static CMYK hsl2Cmyk(HSL hsl){
        return rgb2Cmyk(hsl2Rgb(hsl));
    }
}