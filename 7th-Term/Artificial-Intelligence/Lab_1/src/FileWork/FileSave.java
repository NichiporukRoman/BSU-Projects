package FileWork;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

public class FileSave {
	private String str;
	
	public FileSave(String fileName, String result) {
		PrintWriter writer;
		try {
			writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(fileName), "UTF-8"));
			writer.write(result);
			writer.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public String getStr() {
		return str;
	}
}
