import java.util.*;

public class Treacker {
	static Scanner sc = new Scanner(System.in);
	static int currentRow = 0;

	public static void main(String[] args) {
		// Menu();
		String n = sc.nextLine();
		System.out.println(n);
		sc.close();
	}

	public static void Menu() {
		System.out.println("\n\t\t<--:MENU:-->");
		System.out.println("\nEnter appropriate number to perform following task.");
		System.out.println("1 : Add Expense.");
		System.out.println("2 : Add Income.");
		System.out.println("3 : View Expense.");
		System.out.println("4 : View Income.");
		System.out.println("5 : View Balance.");
		System.out.println("6 : Search Record.");
		System.out.println("7 : Modify Record.");
		System.out.println("8 : Delete Record.");
		System.out.println("9 : Exit.");
		System.out.print("Enter your choice: ");
		int choice = sc.nextInt();
		switch (choice) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			default:
				System.out.println("\n\n\t\tInvalid Choice.\n\n");
		}
	}

	public static void gotoxy(int col, int row) {
		// ANSI escape code to move cursor to row `row` and column `col`
		System.out.print("\033[" + row + ";" + col + "H");
	}

	public static void clrScr() {
		for (int i = 0; i < 50; i++) {
			System.out.println();
		}
		currentRow += 50;
	}
}