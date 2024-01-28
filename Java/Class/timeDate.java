import java.time.*;
import java.time.format.DateTimeFormatter;

public class timeDate{
	public static void main(String[] args){
		LocalDate myDate=LocalDate.now();
		System.out.println(myDate);
		LocalTime myTime=LocalTime.now();
		System.out.println(myTime);
		LocalDateTime myDateTime=LocalDateTime.now();
		System.out.println(myDateTime);
		DateTimeFormatter myFormat=DateTimeFormatter.ofPattern("E, MMM dd yyyy HH:mm:ss");
		String formatDate=myDateTime.format(myFormat);
		System.out.println(formatDate);
	}
}