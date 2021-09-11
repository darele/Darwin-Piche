import java.math.BigInteger;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class llave{

    private static final long PRIME = 1073741783;
    public static void main(final String[] args) {
        final long n = 100000000L;

        long result = 0;
        for (long i = 0; i < n; i++) {
            result = (result + i / 2 + i / 3 + i / 4 + i / 5) % PRIME;
        }
        System.out.println(result);
    }
}