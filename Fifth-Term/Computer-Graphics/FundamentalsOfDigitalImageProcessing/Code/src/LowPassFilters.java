import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class LowPassFilters {
    public static Mat brg2gray(Mat image){
// Преобразование изображения в оттенки серого
        Mat grayImage = new Mat();
        Imgproc.cvtColor(image, grayImage, Imgproc.COLOR_BGR2GRAY);
        return grayImage;
    }

    public static Mat GaussianBlurC(Mat image){
        // Применение низкочастотного фильтра Гаусса
        Mat smoothedImage = new Mat();
        Size kernelSize = new Size(5, 5);
        Imgproc.GaussianBlur(brg2gray(image), smoothedImage, kernelSize, 0);
        return smoothedImage;
    }
}
