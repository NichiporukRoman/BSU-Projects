import org.opencv.core.Mat;
import org.opencv.core.MatOfByte;
import org.opencv.imgcodecs.Imgcodecs;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WindowApp extends JFrame {
    JRadioButton erosionRadioButton, dilationRadioButton, openingRadioButton, closingRadioButton, holeFillingRadioButton,
    gradientRadioButton, topHatRadioButton, blackHatRadioButton, boundaryExtractionRadioButton, hitOrMissRadioButton,
    noiseRemovalRadioButton, smallObjectRemovalRadioButton;
    JPanel radioButtonsM;
    JPanel radioButtonsL;
    JRadioButton grayFilterRadioButton, gaussRadioButton;
    JButton applyButtons, openButton;
    Mat image;
    JTextArea description;
    WindowApp(){
        image = Imgcodecs.imread("C:/Users/tr07s/Downloads/3.png");
        setTitle("FundamentalsOfDigitalImageProcessing");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        ButtonGroup methodChooser = new ButtonGroup();
        ButtonGroup lFilterChooser = new ButtonGroup();
        GridLayout rGridLayout = new GridLayout(16,1);
        radioButtonsM = new JPanel(rGridLayout);
        radioButtonsM.setPreferredSize(new Dimension(175,100));
        radioButtonsM.setBackground(Color.lightGray);
        radioButtonsL = new JPanel(rGridLayout);
        radioButtonsL.setPreferredSize(new Dimension(175,100));
        radioButtonsL.setBackground(Color.lightGray);

        applyButtons = new JButton("Apply");
        openButton = new JButton("Open");

        erosionRadioButton = new JRadioButton("Erosion");
        erosionRadioButton.setBackground(Color.LIGHT_GRAY);
        dilationRadioButton = new JRadioButton("Dilation");
        dilationRadioButton.setBackground(Color.LIGHT_GRAY);
        openingRadioButton = new JRadioButton("Opening");
        openingRadioButton.setBackground(Color.LIGHT_GRAY);
        closingRadioButton = new JRadioButton("Closing");
        closingRadioButton.setBackground(Color.LIGHT_GRAY);
        holeFillingRadioButton = new JRadioButton("Hole-Filling");
        holeFillingRadioButton.setBackground(Color.LIGHT_GRAY);
        gradientRadioButton = new JRadioButton("Gradient");
        gradientRadioButton.setBackground(Color.LIGHT_GRAY);
        topHatRadioButton = new JRadioButton("Top-Hat");
        topHatRadioButton.setBackground(Color.LIGHT_GRAY);
        blackHatRadioButton = new JRadioButton("Black-Hat");
        blackHatRadioButton.setBackground(Color.LIGHT_GRAY);
        boundaryExtractionRadioButton = new JRadioButton("Boundary-Extraction");
        boundaryExtractionRadioButton.setBackground(Color.LIGHT_GRAY);
        hitOrMissRadioButton = new JRadioButton("Hit-or-Miss");
        hitOrMissRadioButton.setBackground(Color.LIGHT_GRAY);
        noiseRemovalRadioButton = new JRadioButton("Noise-Removal");
        noiseRemovalRadioButton.setBackground(Color.LIGHT_GRAY);
        smallObjectRemovalRadioButton = new JRadioButton("Small-Object-Removal");
        smallObjectRemovalRadioButton.setBackground(Color.LIGHT_GRAY);

        grayFilterRadioButton = new JRadioButton("GrayFilter");
        grayFilterRadioButton.setBackground(Color.LIGHT_GRAY);
        gaussRadioButton = new JRadioButton("GaussianBlur");
        gaussRadioButton.setBackground(Color.LIGHT_GRAY);

        ActionListener listener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(erosionRadioButton.isSelected()){
                    description.setText("Erosion is one of the basic operations in image processing theory.\n" +
                            "It is used to reduce the size of objects in an image by removing pixels or elements\n" +
                            "that are on the edge of the object. The erosion operation is based on the use of a\n" +
                            "structural element (also known as a template, kernel or mask) that defines the shape\n" +
                            "and size of the area used to analyze and modify the image.");
                }
                if(dilationRadioButton.isSelected()){
                    description.setText("Dilation is used to increase the size of objects in an image. During\n" +
                            "the dilatation process, the structural element also passes through the image pixel\n" +
                            "by pixel, and if at least one pixel falling under the structural element meets the\n" +
                            "conditions, then the central pixel is dilated (changed to a certain value, usually\n" +
                            "white or the maximum value).");
                }
                if(openingRadioButton.isSelected()){
                    description.setText("Opening is a combination of erosion followed by dilatation and is used to\n" +
                            "remove noise and fine detail in an image.");
                }
                if(closingRadioButton.isSelected()){
                    description.setText("Closure is a combination of dilation followed by erosion and is used\n" +
                            "to close small holes or connect disparate objects in an image.");
                }
                if(holeFillingRadioButton.isSelected()){
                    description.setText("Hole filling is used to fill missing or incomplete areas (holes) in an\n" +
                            "image. Holes can occur due to various reasons such as noise, data loss, or\n" +
                            "incomplete object detection.");
                }
                if(gradientRadioButton.isSelected()){
                    description.setText("Gradient is an important concept in image analysis. It is a vector that\n" +
                            "indicates the direction of the greatest change in the intensity (brightness) of the\n" +
                            "pixels in the image. Gradient is widely used in various image processing and analysis\n" +
                            "tasks such as edge detection, optical flow, segmentation and object recognition.");                }
                if(topHatRadioButton.isSelected()){
                    description.setText("TopHat highlights small light (bright) structures against a dark background.\n" +
                            "To calculate it, first a morphological unlocking operation is applied to the image,\n" +
                            "and then the original image is subtracted. Mathematically, white Tophat can be\n" +
                            "expressed by the following formula.");
                }
                if(blackHatRadioButton.isSelected()){
                    description.setText("BlackHat highlights small dark (dark) structures against a light background.\n" +
                            "To calculate it, first the morphological erosion operation is applied to the image,\n" +
                            "and then the original image is subtracted. Mathematically, black Tophat can be\n" +
                            "expressed by the following formula.");
                }
                if(boundaryExtractionRadioButton.isSelected()){
                    description.setText("Boundary extraction allows you to select the boundaries or contours of\n" +
                            "objects in an image. Borders are transitional areas between different areas of an\n" +
                            "image where changes in brightness, color, or texture occur.");
                }
                if(hitOrMissRadioButton.isSelected()){
                    description.setText("Hit-or-miss transformation is a morphological image processing operation\n" +
                            "that is used to find exact matches of specific patterns or structures in an image.");
                }
                if(noiseRemovalRadioButton.isSelected()){
                    description.setText("Noise removal is the process of processing images or audio signals to\n" +
                            "reduce or remove unwanted artifacts, called noise, that can distort or degrade the\n" +
                            "quality of the signal.");
                }
                if(smallObjectRemovalRadioButton.isSelected()){
                    description.setText("Small object removal is an image processing process aimed at removing\n" +
                            "or eliminating small objects or noise components in an image that may be unwanted\n" +
                            "or disruptive in a particular context or task.");
                }
            }
        };

        erosionRadioButton.addActionListener(listener);
        dilationRadioButton.addActionListener(listener);
        openingRadioButton.addActionListener(listener);
        closingRadioButton.addActionListener(listener);
        holeFillingRadioButton.addActionListener(listener);
        gradientRadioButton.addActionListener(listener);
        topHatRadioButton.addActionListener(listener);
        blackHatRadioButton.addActionListener(listener);
        boundaryExtractionRadioButton.addActionListener(listener);
        hitOrMissRadioButton.addActionListener(listener);
        noiseRemovalRadioButton.addActionListener(listener);
        smallObjectRemovalRadioButton.addActionListener(listener);

        methodChooser.add(erosionRadioButton);
        methodChooser.add(dilationRadioButton);
        methodChooser.add(openingRadioButton);
        methodChooser.add(closingRadioButton);
        methodChooser.add(holeFillingRadioButton);
        methodChooser.add(gradientRadioButton);
        methodChooser.add(topHatRadioButton);
        methodChooser.add(blackHatRadioButton);
        methodChooser.add(boundaryExtractionRadioButton);
        methodChooser.add(hitOrMissRadioButton);
        methodChooser.add(noiseRemovalRadioButton);
        methodChooser.add(smallObjectRemovalRadioButton);

        lFilterChooser.add(grayFilterRadioButton);
        lFilterChooser.add(gaussRadioButton);

        radioButtonsM.add(erosionRadioButton);
        radioButtonsM.add(dilationRadioButton);
        radioButtonsM.add(openingRadioButton);
        radioButtonsM.add(closingRadioButton);
        radioButtonsM.add(holeFillingRadioButton);
        radioButtonsM.add(gradientRadioButton);
        radioButtonsM.add(topHatRadioButton);
        radioButtonsM.add(blackHatRadioButton);
        radioButtonsM.add(boundaryExtractionRadioButton);
        radioButtonsM.add(hitOrMissRadioButton);
        radioButtonsM.add(noiseRemovalRadioButton);
        radioButtonsM.add(smallObjectRemovalRadioButton);

        radioButtonsL.add(grayFilterRadioButton);
        radioButtonsL.add(gaussRadioButton);

        add(radioButtonsM, BorderLayout.EAST);
        add(radioButtonsL, BorderLayout.WEST);

        applyButtons.setPreferredSize(new Dimension(200, 200));
        openButton.setPreferredSize(new Dimension(200, 200));
        applyButtons.addActionListener(new ApplyButtonActionListener());
        openButton.addActionListener(new OpenFileActionListener());

        JPanel p = new JPanel(new GridLayout(1,2));

        description = new JTextArea("Тут будет описание", 6,1);
        description.setPreferredSize(new Dimension(1000,400 ));
        description.setFont(new Font("MS Comic Sans", Font.PLAIN, 32));
        description.setTabSize(10);

        p.add(applyButtons);
        p.add(openButton);
        add(p, BorderLayout.SOUTH);
        add(description, BorderLayout.CENTER);

        setSize(1600,900);
        setResizable(false);
        show();
    }

    private class OpenFileActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JFileChooser fileChooser = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("Изображения", "jpg", "jpeg", "png", "gif");
            fileChooser.setFileFilter(filter);

            int result = fileChooser.showOpenDialog(null);

            if (result == JFileChooser.APPROVE_OPTION) {
                java.io.File selectedFile = fileChooser.getSelectedFile();
                String filePath = selectedFile.getAbsolutePath();
                image = Imgcodecs.imread(filePath);
            }
        }
    }

    private class ApplyButtonActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if(grayFilterRadioButton.isSelected()){
                if(erosionRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Erosion(LowPassFilters.brg2gray(image)), "Erosion-Gray");
                }
                if(dilationRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Dilation(LowPassFilters.brg2gray(image)), "Dilation-Gray");
                }
                if(openingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Opening(LowPassFilters.brg2gray(image)), "Opening-Gray");
                }
                if(closingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Closing(LowPassFilters.brg2gray(image)), "Closing-Gray");
                }
                if(holeFillingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.HoleFilling(LowPassFilters.brg2gray(image)), "HoleFilling-Gray");
                }
                if(gradientRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Gradient(LowPassFilters.brg2gray(image)), "Gradient-Gray");
                }
                if(topHatRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.TopHat(LowPassFilters.brg2gray(image)), "TopHat-Gray");
                }
                if(blackHatRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.BlackHat(LowPassFilters.brg2gray(image)), "BlackHat-Gray");
                }
                if(boundaryExtractionRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.BoundaryExtraction(LowPassFilters.brg2gray(image)), "BoundaryExtraction-Gray");
                }
                if(hitOrMissRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.HitOrMiss(LowPassFilters.brg2gray(image)), "HitOrMiss-Gray");
                }
                if(noiseRemovalRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.NoiseRemoval(LowPassFilters.brg2gray(image)), "NoiseRemoval-Gray");
                }
                if(smallObjectRemovalRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.SmallObjectRemoval(LowPassFilters.brg2gray(image)), "SmallObjectRemoval-Gray");
                }
            }
            if(gaussRadioButton.isSelected()){

                if(erosionRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Erosion(LowPassFilters.GaussianBlurC(image)), "Erosion-Gauss");
                }
                if(dilationRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Dilation(LowPassFilters.GaussianBlurC(image)), "Dilation-Gauss");
                }
                if(openingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Opening(LowPassFilters.GaussianBlurC(image)), "Opening-Gauss");
                }
                if(closingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Closing(LowPassFilters.GaussianBlurC(image)), "Closing-Gauss");
                }
                if(holeFillingRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.HoleFilling(LowPassFilters.GaussianBlurC(image)), "HoleFilling-Gauss");
                }
                if(gradientRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.Gradient(LowPassFilters.brg2gray(image)), "Gradient-Gauss");
                }
                if(topHatRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.TopHat(LowPassFilters.GaussianBlurC(   image)), "TopHat-Gauss");
                }
                if(blackHatRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.BlackHat(LowPassFilters.GaussianBlurC(image)), "BlackHat-Gauss");
                }
                if(boundaryExtractionRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.BoundaryExtraction(LowPassFilters.GaussianBlurC(image)), "BoundaryExtraction-Gauss");
                }
                if(hitOrMissRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.HitOrMiss(LowPassFilters.GaussianBlurC(image)), "HitOrMiss-Gauss");
                }
                if(noiseRemovalRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.NoiseRemoval(LowPassFilters.GaussianBlurC(image)), "NoiseRemoval-Gauss");
                }
                if(smallObjectRemovalRadioButton.isSelected()){
                    displayImage(MorphologicalProcessing.SmallObjectRemoval(LowPassFilters.GaussianBlurC(image)), "SmallObjectRemoval-Gauss");
                }
            }
        }
    }
    public static void displayImage(Mat image, String windowName) {
        MatOfByte matOfByte = new MatOfByte();
        Imgcodecs.imencode(".jpg", image, matOfByte);
        byte[] byteArray = matOfByte.toArray();
        ImageIcon imageIcon = new ImageIcon(byteArray);
        JFrame frame = new JFrame(windowName);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.getContentPane().setLayout(new FlowLayout());
        frame.getContentPane().add(new JLabel(imageIcon));
        frame.pack();
        frame.setVisible(true);
    }
}
