package fundamentals.Tests;

import de.adelhabib.fundamentals.FixedCapacityStack;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInstance;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class StackTest {

    @Test
    public void testStack(){
        FixedCapacityStack<Integer> s = new FixedCapacityStack<>(100);
        for (int i = 0; i < 100; i++) {
            s.push(i);
            assertEquals(i+1,s.size());
        }
        for (int i = 0; i < 100; i++) {
            int top = s.pop();
            assertEquals(100-i-1,top);
        }
    }
}
