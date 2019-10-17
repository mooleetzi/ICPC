public class InputReader{
    StreamTokenizer tokenizer;
    public InputReader(InputStream stream){
        tokenizer=new StreamTokenizer(new BufferedReader(new InputStreamReader(stream)));
        tokenizer.ordinaryChars(33,126);
        tokenizer.wordChars(33,126);
    }
    public String next() throws IOException {
        tokenizer.nextToken();
        return tokenizer.sval;
    }
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    public boolean hasNext() throws IOException {
        int res=tokenizer.nextToken();
        tokenizer.pushBack();
        return res!=tokenizer.TT_EOF;
    }
}