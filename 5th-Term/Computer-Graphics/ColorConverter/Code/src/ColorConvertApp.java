import ColorSystem.CMYK;
import ColorSystem.HSL;
import ColorSystem.RGB;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ColorConvertApp extends JFrame {
    private final JSlider rRGBSlider;
    private final JSlider gRGBSlider;
    private final JSlider bRGBSlider;
    private final JSlider hHSLSlider;
    private final JSlider sHSLSlider;
    private final JSlider lHSLSlider;
    private final JSlider cCmykSlider;
    private final JSlider mCmykSlider;
    private final JSlider yCmykSlider;
    private final JSlider kCmykSlider;
    private final JTextField rRGBTextField;
    private final JTextField gRGBTextField;
    private final JTextField bRGBTextField;
    private final JTextField hHSLTextField;
    private final JTextField sHSLTextField;
    private final JTextField lHSLTextField;
    private final JTextField cCmykTextField;
    private final JTextField mCmykTextField;
    private final JTextField yCmykTextField;
    private final JTextField kCmykTextField;
    private RGB rgb;
    private CMYK cmyk;
    private HSL hsl;
    private final JPanel palette;

    public ColorConvertApp() {
        setTitle("Color App");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel colors = new JPanel();
        palette = new JPanel();
        palette.setBackground(Color.WHITE);

        rgb = new RGB(0, 0, 0);
        cmyk = new CMYK(0,0,0,0);
        hsl = new HSL(0,0,0);

        rRGBSlider = new JSlider(JSlider.VERTICAL, 0, 255, 255);
        gRGBSlider = new JSlider(JSlider.VERTICAL, 0, 255, 255);
        bRGBSlider = new JSlider(JSlider.VERTICAL, 0, 255, 255);

        cCmykSlider = new JSlider(JSlider.VERTICAL, 0, 100, 0);
        mCmykSlider = new JSlider(JSlider.VERTICAL, 0, 100, 0);
        yCmykSlider = new JSlider(JSlider.VERTICAL, 0, 100, 0);
        kCmykSlider = new JSlider(JSlider.VERTICAL, 0, 100, 0);

        hHSLSlider = new JSlider(JSlider.VERTICAL, 0, 360, 0);
        lHSLSlider = new JSlider(JSlider.VERTICAL, 0, 100, 100);
        sHSLSlider = new JSlider(JSlider.VERTICAL, 0, 100, 0);

        rRGBTextField = new JTextField("255");
        rRGBTextField.setPreferredSize(new Dimension(40,40));
        rRGBTextField.setHorizontalAlignment(0);
        gRGBTextField = new JTextField("255");
        gRGBTextField.setHorizontalAlignment(0);
        gRGBTextField.setPreferredSize(new Dimension(40,40));
        bRGBTextField = new JTextField("255");
        bRGBTextField.setHorizontalAlignment(0);
        bRGBTextField.setPreferredSize(new Dimension(40,40));

        JLabel rRGBLabel = new JLabel("R:");
        rRGBLabel.setHorizontalAlignment(0);
        JLabel gRGBLabel = new JLabel("G:");
        gRGBLabel.setHorizontalAlignment(0);
        JLabel bRGBLabel = new JLabel("B:");
        bRGBLabel.setHorizontalAlignment(0);

        cCmykTextField = new JTextField("0");
        cCmykTextField.setHorizontalAlignment(0);
        cCmykTextField.setPreferredSize(new Dimension(40,40));
        mCmykTextField = new JTextField("0");
        mCmykTextField.setHorizontalAlignment(0);
        mCmykTextField.setPreferredSize(new Dimension(40,40));
        yCmykTextField = new JTextField("0");
        yCmykTextField.setHorizontalAlignment(0);
        yCmykTextField.setPreferredSize(new Dimension(40,40));
        kCmykTextField = new JTextField("0");
        kCmykTextField.setHorizontalAlignment(0);
        kCmykTextField.setPreferredSize(new Dimension(40,40));

        JLabel cCmykLabel = new JLabel("C:");
        cCmykLabel.setHorizontalAlignment(0);
        JLabel mCmykLabel = new JLabel("M:");
        mCmykLabel.setHorizontalAlignment(0);
        JLabel yCmykLabel = new JLabel("Y:");
        yCmykLabel.setHorizontalAlignment(0);
        JLabel kCmykLabel = new JLabel("K:");
        kCmykLabel.setHorizontalAlignment(0);

        hHSLTextField = new JTextField("0");
        hHSLTextField.setPreferredSize(new Dimension(40,40));
        hHSLTextField.setHorizontalAlignment(0);
        sHSLTextField = new JTextField("0");
        sHSLTextField.setHorizontalAlignment(0);
        sHSLTextField.setPreferredSize(new Dimension(40,40));
        lHSLTextField = new JTextField("100");
        lHSLTextField.setHorizontalAlignment(0);
        lHSLTextField.setPreferredSize(new Dimension(40,40));

        JLabel hHSLLabel = new JLabel("H:");
        hHSLLabel.setHorizontalAlignment(0);
        JLabel sHSLLabel = new JLabel("S:");
        sHSLLabel.setHorizontalAlignment(0);
        JLabel lHSLLabel = new JLabel("L:");
        lHSLLabel.setHorizontalAlignment(0);

        JButton applyButtonRGB = new JButton("Apply");
        JButton applyButtonCMYK = new JButton("Apply");
        JButton applyButtonHSL = new JButton("Apply");

        applyButtonRGB.addActionListener(new ApplyButtonListenerRGB());
        applyButtonCMYK.addActionListener(new ApplyButtonListenerCMYK());
        applyButtonHSL.addActionListener(new ApplyButtonListenerHSL());

        rRGBSlider.addMouseMotionListener(new SliderMouseListenerRGB());
        gRGBSlider.addMouseMotionListener(new SliderMouseListenerRGB());
        bRGBSlider.addMouseMotionListener(new SliderMouseListenerRGB());

        cCmykSlider.addMouseMotionListener(new SliderMouseListenerCMYK());
        mCmykSlider.addMouseMotionListener(new SliderMouseListenerCMYK());
        yCmykSlider.addMouseMotionListener(new SliderMouseListenerCMYK());
        kCmykSlider.addMouseMotionListener(new SliderMouseListenerCMYK());

        hHSLSlider.addMouseMotionListener(new SliderMouseListenerHSL());
        sHSLSlider.addMouseMotionListener(new SliderMouseListenerHSL());
        lHSLSlider.addMouseMotionListener(new SliderMouseListenerHSL());


        JPanel colorPanelRGB = new JPanel();
        JPanel colorPanelCMYK = new JPanel();
        JPanel colorPanelHSL = new JPanel();
        colorPanelRGB.setBackground(Color.WHITE);
        colorPanelCMYK.setBackground(Color.WHITE);
        colorPanelHSL.setBackground(Color.WHITE);

        JButton chooseColorButton = new JButton("Choose Color");

        chooseColorButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                    Color selectedColor = JColorChooser.showDialog(ColorConvertApp.this, "Choose a color", Color.WHITE);
                    if (selectedColor != null) {
                    rgb.setRed(selectedColor.getRed());
                    rgb.setGreen(selectedColor.getGreen());
                    rgb.setBlue(selectedColor.getBlue());

                    cmyk = СonversionOperations.rgb2Cmyk(rgb);
                    hsl = СonversionOperations.rgb2Hsl(rgb);

                    SetRGBTextField();
                    SetRGBSlider();
                    SetCMYKTextField();
                    SetCMYKSlider();
                    SetHSLTextField();
                    SetHSLSlider();

                    palette.setBackground(new Color(rgb.getRed(),rgb.getGreen(),rgb.getBlue()));
                }
            }
        });

        chooseColorButton.setPreferredSize(new Dimension(1600,100));
        JPanel b1 = new JPanel(new GridLayout(3,2));
        JPanel b2 = new JPanel(new GridLayout(4,2));
        JPanel b3 = new JPanel(new GridLayout(3,2));

        b1.add(rRGBLabel);
        b1.add(rRGBTextField);
        b1.add(gRGBLabel);
        b1.add(gRGBTextField);
        b1.add(bRGBLabel);
        b1.add(bRGBTextField);
        colorPanelRGB.add(b1);
        colorPanelRGB.add(applyButtonRGB);
        colorPanelRGB.add(rRGBSlider);
        colorPanelRGB.add(gRGBSlider);
        colorPanelRGB.add(bRGBSlider);

        b2.add(cCmykLabel);
        b2.add(cCmykTextField);
        b2.add(mCmykLabel);
        b2.add(mCmykTextField);
        b2.add(yCmykLabel);
        b2.add(yCmykTextField);
        b2.add(kCmykLabel);
        b2.add(kCmykTextField);
        colorPanelCMYK.add(b2);
        colorPanelCMYK.add(applyButtonCMYK);
        colorPanelCMYK.add(cCmykSlider);
        colorPanelCMYK.add(mCmykSlider);
        colorPanelCMYK.add(yCmykSlider);
        colorPanelCMYK.add(kCmykSlider);

        b3.add(hHSLLabel);
        b3.add(hHSLTextField);
        b3.add(sHSLLabel);
        b3.add(sHSLTextField);
        b3.add(lHSLLabel);
        b3.add(lHSLTextField);
        colorPanelHSL.add(b3);
        colorPanelHSL.add(applyButtonHSL);
        colorPanelHSL.add(hHSLSlider);
        colorPanelHSL.add(sHSLSlider);
        colorPanelHSL.add(lHSLSlider);
        add(chooseColorButton, BorderLayout.SOUTH);
        colors.add(colorPanelRGB);
        colors.add(colorPanelCMYK);
        colors.add(colorPanelHSL);
        colors.setLayout(new GridLayout(1,3));
        palette.setPreferredSize(new Dimension(600,500));
        add(palette, BorderLayout.NORTH);
        add(colors, BorderLayout.CENTER);
        setSize(1600,900);
        setResizable(false);
        show();
    }

    private class SliderMouseListenerRGB extends MouseMotionAdapter {
        public void mouseDragged(MouseEvent e) {
            int redValue = rRGBSlider.getValue();
            int greenValue = gRGBSlider.getValue();
            int blueValue = bRGBSlider.getValue();

            rgb.setRed(redValue);
            rgb.setGreen(greenValue);
            rgb.setBlue(blueValue);

            cmyk = СonversionOperations.rgb2Cmyk(rgb);
            hsl = СonversionOperations.rgb2Hsl(rgb);

            SetRGBTextField();
            SetCMYKTextField();
            SetCMYKSlider();
            SetHSLTextField();
            SetHSLSlider();

            palette.setBackground(new Color(redValue, greenValue, blueValue));
        }
    }
    private class SliderMouseListenerCMYK extends MouseMotionAdapter {
        public void mouseDragged(MouseEvent e) {
            int cyanValue = cCmykSlider.getValue();
            int magentaValue = mCmykSlider.getValue();
            int yellowValue = yCmykSlider.getValue();
            int key = kCmykSlider.getValue();

            cmyk.setCyan(cyanValue);
            cmyk.setMagenta(magentaValue);
            cmyk.setYellow(yellowValue);
            cmyk.setKey(key);

            rgb = СonversionOperations.cmyk2Rgb(cmyk);
            hsl = СonversionOperations.cmyk2Hsl(cmyk);

            SetRGBTextField();
            SetRGBSlider();
            SetCMYKTextField();
            SetHSLTextField();
            SetHSLSlider();

            palette.setBackground(new Color(rgb.getRed(), rgb.getGreen(), rgb.getBlue()));
        }
    }
    private class ApplyButtonListenerCMYK implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                int cyanValue = Integer.parseInt(cCmykTextField.getText());
                int magentaValue = Integer.parseInt(mCmykTextField.getText());
                int yellowValue = Integer.parseInt(yCmykTextField.getText());
                int key = Integer.parseInt(kCmykTextField.getText());

                cmyk.setCyan(cyanValue);
                cmyk.setMagenta(magentaValue);
                cmyk.setYellow(yellowValue);
                cmyk.setKey(key);

                rgb = СonversionOperations.cmyk2Rgb(cmyk);
                hsl = СonversionOperations.cmyk2Hsl(cmyk);

                SetRGBTextField();
                SetRGBSlider();
                SetCMYKSlider();
                SetCMYKTextField();
                SetHSLTextField();
                SetHSLSlider();

                palette.setBackground(new Color(rgb.getRed(), rgb.getGreen(), rgb.getBlue()));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(ColorConvertApp.this, "Invalid input. Please enter numeric values.");
            }
        }
    }
    private class ApplyButtonListenerRGB implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                int redValue = Integer.parseInt(rRGBTextField.getText());
                int greenValue = Integer.parseInt(gRGBTextField.getText());
                int blueValue = Integer.parseInt(bRGBTextField.getText());

                rgb.setRed(redValue);
                rgb.setGreen(greenValue);
                rgb.setBlue(blueValue);

                cmyk = СonversionOperations.rgb2Cmyk(rgb);
                hsl = СonversionOperations.rgb2Hsl(rgb);

                SetRGBSlider();
                SetRGBTextField();
                SetCMYKTextField();
                SetCMYKSlider();
                SetHSLTextField();
                SetHSLSlider();

                palette.setBackground(new Color(rgb.getRed(), rgb.getGreen(), rgb.getBlue()));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(ColorConvertApp.this, "Invalid input. Please enter numeric values.");
            }
        }
    }
    private class ApplyButtonListenerHSL implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                int hue = Integer.parseInt(hHSLTextField.getText());
                int saturation = Integer.parseInt(sHSLTextField.getText());
                int lightness = Integer.parseInt(lHSLTextField.getText());

                hsl.setHue(hue);
                hsl.setSaturation(saturation);
                hsl.setLightness(lightness);

                cmyk = СonversionOperations.hsl2Cmyk(hsl);
                rgb = СonversionOperations.hsl2Rgb(hsl);

                SetRGBTextField();
                SetRGBSlider();
                SetCMYKTextField();
                SetCMYKSlider();
                SetHSLSlider();
                SetHSLTextField();

                palette.setBackground(new Color(rgb.getRed(), rgb.getGreen(), rgb.getBlue()));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(ColorConvertApp.this, "Invalid input. Please enter numeric values.");
            }
        }
    }
    private class SliderMouseListenerHSL extends MouseMotionAdapter {
        public void mouseDragged(MouseEvent e) {
            int hue = hHSLSlider.getValue();
            int saturation = sHSLSlider.getValue();
            int lightness = lHSLSlider.getValue();

            hsl.setHue(hue);
            hsl.setSaturation(saturation);
            hsl.setLightness(lightness);

            cmyk = СonversionOperations.hsl2Cmyk(hsl);
            rgb = СonversionOperations.hsl2Rgb(hsl);

            SetRGBTextField();
            SetRGBSlider();
            SetCMYKTextField();
            SetCMYKSlider();
            SetHSLTextField();
            SetHSLTextField();

            palette.setBackground(new Color(rgb.getRed(), rgb.getGreen(), rgb.getBlue()));
        }
    }

    private void SetRGBTextField(){
        rRGBTextField.setText(String.valueOf(rgb.getRed()));
        gRGBTextField.setText(String.valueOf(rgb.getGreen()));
        bRGBTextField.setText(String.valueOf(rgb.getBlue()));
    }
    private void SetCMYKTextField(){
        cCmykTextField.setText(String.valueOf(cmyk.getCyan()));
        mCmykTextField.setText(String.valueOf(cmyk.getMagenta()));
        yCmykTextField.setText(String.valueOf(cmyk.getYellow()));
        kCmykTextField.setText(String.valueOf(cmyk.getKey()));
    }
    private void SetHSLTextField(){
        hHSLTextField.setText(String.valueOf(hsl.getHue()));
        sHSLTextField.setText(String.valueOf((int) hsl.getSaturation()));
        lHSLTextField.setText(String.valueOf((int) hsl.getLightness()));
    }
    private void SetRGBSlider(){
        rRGBSlider.setValue(rgb.getRed());
        gRGBSlider.setValue(rgb.getGreen());
        bRGBSlider.setValue(rgb.getBlue());
    }
    private void SetCMYKSlider(){
        cCmykSlider.setValue(cmyk.getCyan());
        mCmykSlider.setValue(cmyk.getMagenta());
        yCmykSlider.setValue(cmyk.getYellow());
        kCmykSlider.setValue(cmyk.getKey());
    }
    private void SetHSLSlider(){
        hHSLSlider.setValue(hsl.getHue());
        sHSLSlider.setValue((int) hsl.getSaturation());
        lHSLSlider.setValue((int) hsl.getLightness());
    }
}