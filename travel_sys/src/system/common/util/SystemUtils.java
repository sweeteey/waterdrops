package system.common.util;

import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Properties;

public class SystemUtils {

	public static final String timeFormat1 = "yyyy-MM-dd";
	public static final String timeFormat2 = "yyyy-MM-dd HH:mm:ss";
	public static final String timeFormat3 = "HH:mm:ss";
	public static final String timeFlowNumber = "yyyyhhmmsss";

	public static String toFirstUp(String str) {
		String result = "";
		String str1 = str.substring(0, 1);
		String str2 = "";
		if (str.length() > 1) {
			str2 = str.substring(1, str.length());
		}
		result = str1.toUpperCase() + str2;
		return result;
	}

	public static String toFirstDown(String str) {
		String result = "";
		String str1 = str.substring(0, 1);
		String str2 = "";
		if (str.length() > 1) {
			str2 = str.substring(1, str.length());
		}
		result = str1.toLowerCase() + str2;
		return result;
	}

	public static String getCurrentTimeToString(String format) {
		SimpleDateFormat sdf = new SimpleDateFormat(format);
		return sdf.format(new Date());
	}

	public static String getCurrentTimeFlowNumber(String format) {
		SimpleDateFormat sdf = new SimpleDateFormat(format);
		return sdf.format(new Date());
	}

	@SuppressWarnings("unused")
	public static Properties getPropertiesUnderClassPathByName(String filename) {
		Properties properties = new Properties();
		InputStream _fis = null;
		try {
			_fis = Thread.currentThread().getContextClassLoader()
					.getResourceAsStream(filename);
			properties.load(_fis); 
			String work_begin = properties.getProperty("work_begin");
			String work_end = properties.getProperty("work_end");
		} catch (Exception e) {
			e.printStackTrace();
		}
		return properties;
	}

	public static boolean compareNowTimeBetweenTimes() {
		 
		return true;
	}
	public static String url = "https://" + SystemUtils._URL
			+ "/svn/it_doc/xiaoli/sysparam";
 

	public static final String _URL = "";


	public static final String _PACKAGE = "graduation.design";
	public static final String _PACKAGE2 = "graduation/design";
	public static final String _ENCODE = "gbk";
	
}
