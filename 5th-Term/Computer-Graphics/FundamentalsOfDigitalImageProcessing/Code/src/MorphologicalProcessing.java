import org.opencv.core.*;
import org.opencv.highgui.HighGui;
import org.opencv.imgproc.Imgproc;

import static org.opencv.imgproc.Imgproc.THRESH_BINARY;
import static org.opencv.imgproc.Imgproc.threshold;

public class MorphologicalProcessing {
    static public Mat Erosion(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat erodedImage = new Mat();
        Imgproc.erode(image, erodedImage, kernel);
        return erodedImage;
    }

    static public Mat Dilation(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat dilatedImage = new Mat();
        Imgproc.dilate(image, dilatedImage, kernel);
        return dilatedImage;
    }

    static public Mat Opening(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat openedImage = new Mat();
        Imgproc.morphologyEx(image, openedImage, Imgproc.MORPH_OPEN, kernel);
        return openedImage;
    }

    static public Mat Closing(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat closedImage = new Mat();
        Imgproc.morphologyEx(image, closedImage, Imgproc.MORPH_CLOSE, kernel);
        return  closedImage;
    }

    static public Mat HoleFilling(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat filledImage = new Mat();
        Imgproc.morphologyEx(image, filledImage, Imgproc.MORPH_CLOSE, kernel);
        return  filledImage;
    }

    static public Mat Gradient(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat gradientImage = new Mat();
        Imgproc.morphologyEx(image, gradientImage, Imgproc.MORPH_GRADIENT, kernel);
        return  gradientImage;
    }

    static public Mat TopHat(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat topHatImage = new Mat();
        Imgproc.morphologyEx(image, topHatImage, Imgproc.MORPH_TOPHAT, kernel);
        return  topHatImage;
    }

    static public Mat BlackHat(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat blackHatImage = new Mat();
        Imgproc.morphologyEx(image, blackHatImage, Imgproc.MORPH_BLACKHAT, kernel);
        return  blackHatImage;
    }

    static public Mat BoundaryExtraction(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat boundaryImage = new Mat();
        Imgproc.morphologyEx(image, boundaryImage, Imgproc.MORPH_GRADIENT, kernel);
        return  boundaryImage;
    }

    static public Mat HitOrMiss(Mat image){
        Mat kernel = new Mat( 3, 3, CvType.CV_16S );    
        Mat binarized = image;
        kernel.put(0 ,0, 0, -1, 0, -1, 1, -1, 0, -1, 0 );
        Mat output_image = new Mat();
        Imgproc.morphologyEx(binarized, output_image, Imgproc.MORPH_HITMISS, kernel);
        Core.add(kernel, new Scalar(1), kernel);
        Core.multiply(kernel, new Scalar(127), kernel);
        kernel.convertTo(kernel, CvType.CV_8U);
        return output_image;
    }

    static public Mat NoiseRemoval(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat denoisedImage = new Mat();
        Imgproc.morphologyEx(image, denoisedImage, Imgproc.MORPH_OPEN, kernel);
        return denoisedImage;
    }

    static public Mat SmallObjectRemoval(Mat image){
        Mat kernel = Imgproc.getStructuringElement(Imgproc.MORPH_RECT, new Size(3, 3));
        Mat removedImage = new Mat();
        Imgproc.morphologyEx(image, removedImage, Imgproc.MORPH_OPEN, kernel);
        return removedImage;
    }
}
