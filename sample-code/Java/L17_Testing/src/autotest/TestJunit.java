package autotest;

import static org.junit.Assert.assertEquals;

import org.junit.Test;
public class TestJunit {
    @Test
    public void test() {
        // assertEquals("Hello world","hello world");  
    	String s = "Hello world";
        assertEquals(s,"hello world");  
    }
}