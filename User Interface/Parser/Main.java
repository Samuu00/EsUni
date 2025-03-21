package Parser;

public class Main {
    public static void main(String[] args) {
        OptionParser parser = new OptionParser();
        parser.Parse(args);

        if (parser.isFoundPrintOption()) {
            String[] sampleArray = {"Hello", "world!\n"};
            Actions.print(sampleArray);
        }

        if (parser.isFoundReadOption()) {
            int[] numbers = Actions.read(parser.getN());
            Actions.print(numbers);
            System.out.print("\n");
        }

        if (parser.isFoundReadUntilOption()) {
            String result = Actions.read(parser.getC());
            System.out.println(result);
            System.out.print("\n");
        }
    }
}