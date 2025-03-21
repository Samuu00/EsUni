package Parser;

public class OptionParser {
    private boolean foundPrintOption;
    private boolean foundReadOption;
    private boolean foundReadUntilOption;
    private int n;
    private char c;

    public OptionParser() {
        foundPrintOption = false;
        foundReadOption = false;
        foundReadUntilOption = false;
        n = -1;
        c = '.';
    }

    public void Parse(String[] args) {
        for (int i = 0; i < args.length; i++) {
            String opt = args[i].toLowerCase();
            switch (opt) {
                case "--print":
                    foundPrintOption = true;
                    break;
                case "--read":
                    foundReadOption = true;
                    if (i + 1 < args.length) {
                        n = Integer.parseInt(args[++i]);
                    }
                    break;
                case "--read-until":
                    foundReadUntilOption = true;
                    if (i + 1 < args.length) {
                        c = args[++i].charAt(0);
                    }
                    break;
            }
        }
    }
    public boolean isFoundPrintOption() {
        return foundPrintOption;
    }

    public boolean isFoundReadOption() {
        return foundReadOption;
    }

    public boolean isFoundReadUntilOption() {
        return foundReadUntilOption;
    }

    public int getN() {
        return n;
    }

    public char getC() {
        return c;
    }
}
