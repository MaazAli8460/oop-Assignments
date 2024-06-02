#include "ZooChain.cpp"
#include "String.cpp"
#include "BinaryStore.cpp"
#include <gtest/gtest.h>

// QUESTION 1

// TEST 1
TEST(ZooCage, add_Cage) {
	ZooChain obj;
	char name1[8] = "Girrafe";
	char name2[7] = "Toucan";
	char name3[8] = "Penguin";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	EXPECT_TRUE(true);
}

// TEST 2
TEST(ZooCage, print_Chain) {
	ZooChain obj;
	obj.print_Chain();
	char name1[9] = "Elephant";
	char name2[5] = "Wolf";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.print_Chain();

	EXPECT_TRUE(true);
}

// TEST 3
TEST(ZooCage, delete_Chain) {
	ZooChain obj;
	char name1[7] = "TOUCAN";
	obj.add_Cage(name1, 12);
	obj.delete_Chain(12);
	EXPECT_EQ(NULL, (obj.start));
	char name2[5] = "BEAR";
	char name3[8] = "OSTRICH";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.delete_Chain(7);
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->name)));
	EXPECT_EQ(NULL, obj.start->link->link);
	char name4[5] = "WOLF";
	obj.add_Cage(name4, 5);
	EXPECT_EQ(0, strcmp(name4, (obj.start->link->link->name)));

}

// TEST 4
TEST(ZooCage, Sort_Chain) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 10);
	obj.add_Cage(name2, 15);
	obj.add_Cage(name3, 8);
	obj.Sort_Chain();

	EXPECT_EQ(0, strcmp(name3, (obj.start->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name2, (obj.start->link->link->name)));
	
	char name4[5] = "DEER";
	obj.add_Cage(name4, 6);

	obj.Sort_Chain();
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->link->name)));
	EXPECT_EQ(0, strcmp(name2, (obj.start->link->link->link->name)));
	EXPECT_EQ(0, strcmp(name4, (obj.start->name)));

}

// TEST 5
TEST(ZooCage, remove_Duplicate) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.add_Cage(name1, 12);
	obj.add_Cage(name1, 12);
	obj.remove_Duplicate();

	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	ZooChain obj1;
	obj1.add_Cage(name2, 7);
	obj1.add_Cage(name2, 7);
	obj1.add_Cage(name2, 7);
	obj1.remove_Duplicate();
	EXPECT_EQ(0, strcmp(name2, obj1.start->name));
}

// TEST 6
TEST(ZooCage, update_name_at_cageNumber) {
	ZooChain obj;
	char name1[5] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 15);
	obj.add_Cage(name3, 8);

	obj.update_name_at_cageNumber(8, "PENGUIN");
	obj.update_name_at_cageNumber(12, "OSTRICH");
	obj.update_name_at_cageNumber(15, "TOUCAN");

	EXPECT_EQ(0, strcmp(obj.start->name, "OSTRICH"));
	EXPECT_EQ(0, strcmp(obj.start->link->name, "TOUCAN"));
	EXPECT_EQ(0, strcmp(obj.start->link->link->name, "PENGUIN"));

}

// QUESTION 2

// TEST 1
TEST(String, Constructors) {
	char s[] = "Assignment2";
	String str(s);
	ASSERT_EQ(0, strcmp("Assignment2", str.getdata()));

	String str1(7);
	ASSERT_EQ(0, strcmp("", str1.getdata()));

	String str2(str);
	ASSERT_EQ(0, strcmp(str2.getdata(), str.getdata()));
	ASSERT_NE(str2.getdata(), str1.getdata());

}

// TEST 2
TEST(String, getChar) {
	char s[] = "World!";
	String str(s);
	ASSERT_EQ('!', str.getChar(5));
	ASSERT_EQ('\0', str.getChar(6));

	String str1(str);
	ASSERT_EQ('W', str.getChar(0));
}

// TEST 3
TEST(String, isEmpty) {
	char st[] = "Assignment2";
	String str(st);
	ASSERT_EQ(false, str.isEmpty());
	ASSERT_EQ(11, str.length());

	String str1(7);
	ASSERT_EQ(true, str1.isEmpty());
	ASSERT_EQ(0, str1.length());
}

// TEST 4
TEST(String, index_at) {
	char st[] = "Asssignment-2";
	String str(st);
	ASSERT_EQ(0, str.index_at('A'));
	ASSERT_EQ(5, str.index_at('g'));
	ASSERT_EQ(1, str.index_at('s'));
	ASSERT_EQ(12, str.index_at('2'));
	ASSERT_EQ(-1, str.index_at('P'));

	char st1[] = "OOP-Assignment2";
	char t[] = "ment";
	String test(t);
	string test1(t);
	String str1(st1);
	ASSERT_EQ(6, str1.index_at("sign"));
	ASSERT_EQ(10, str1.index_at(test));
	ASSERT_EQ(10, str1.index_at(test1));
}

// TEST 5
TEST(String, isEqual) {
	char st[] = "oop-A02";
	String str(st);

	char t1[] = "oop", t2[] = "A02", t3[] = "oop-a02", t4[] = "oop-A02";
	ASSERT_EQ(false, str.isEqual(t1));
	ASSERT_EQ(false, str.isEqual(t2));
	ASSERT_EQ(false, str.isEqual(t3));
	ASSERT_EQ(true, str.isEqual(t4));

	char st1[] = "Spring";
	String str1(st1);

	char t11[] = "spring", t12[] = "sprIng";
	ASSERT_EQ(false, str1.isEqual(t11));
	ASSERT_EQ(false, str1.isEqual(t12));
	ASSERT_EQ(true, str1.isEqual(st1));
}

// TEST 6
TEST(String, append_string) {
	char st[] = "As";
	String str(st);
	char t1[] = "sign";
	string t2 = "ment";
	String str1(str);
	char t3 = 'g';
	str.append_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assign"));
	str.append_string(t2);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assignment"));
	str.append_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "AssignmentAs"));
	str.append_string(t3);
	ASSERT_EQ(0, strcmp(str.getdata(), "AssignmentAsg"));
}

// TEST 7
TEST(String, remove_string) {
	char st[] = "OOP-A02";
	String str(st);
	
	str.remove_string('-');
	ASSERT_EQ(0, strcmp(str.getdata(), "OOPA02"));
	ASSERT_EQ(6, str.length());

	string t1 = "A0";
	str.remove_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "OOP2"));
	ASSERT_EQ(4, str.length());

	char t2[] = "OO";
	str.remove_string(t2);
	ASSERT_EQ(0, strcmp(str.getdata(), "P2"));
	ASSERT_EQ(2, str.length());

	String str1("2");
	str.remove_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "P"));
	ASSERT_EQ(1, str.length());

}

// TEST 8
TEST(String, assign_string) {
	char st[] = "OOP-Assignment02";
	String str(st);
	
	str.assign_string("Hello!");
	ASSERT_EQ(0, strcmp(str.getdata(), "Hello!"));
	ASSERT_EQ(6, str.length());

	string t1 = "OOP-A02";
	str.assign_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "OOP-A02"));
	ASSERT_EQ(7, str.length());

	String str1("1");
	str.assign_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "1"));
	ASSERT_EQ(1, str.length());

}

// QUESTION 3

// TEST START
TEST(BinaryStore, start) {
	BinaryStore x(3);
	x.add_Address("0000");
	x.add_Address("0001");
	x.add_Address("0010");

	x.set_Byte("0000", "01010100");
	x.set_Byte("0001", "00011100");

	EXPECT_EQ(strcmp(x.Get("0000"), "01010100"), 0);
	EXPECT_EQ(strcmp(x.Get("0001"), "00011100"),0);
	EXPECT_EQ(x.Get("0010"), nullptr);

}

// TEST START1
TEST(BinaryStore, start1) {
	BinaryStore x(2);
	x.add_Address("0000");
	x.add_Address("0001");

	x.set_Byte("0000", "01100110");
	x.set_Byte("0010", "01010111");

	EXPECT_EQ(strcmp(x.Get("0000"), "01100110"), 0);
	EXPECT_EQ(strcmp(x.Get("0010"), "01010111"), 0);

	x.set_Byte("0000", "10000001");
	EXPECT_EQ(strcmp(x.Get("0000"), "10000001"), 0);
}

// TEST ADD
TEST(BinaryStore, Add) {
	BinaryStore x;
	char byt[] = "00000110";
	char byt2[] = "01110000";
	EXPECT_EQ(0, strcmp(x.Add(byt, byt2), "01110110"));
}

// TEST ADD1
TEST(BinaryStore, Add1) {
	BinaryStore x;
	char byt[] = "11101010";
	char byt2[] = "01010110";
	EXPECT_EQ(strcmp(x.Add(byt, byt2), "01000000"), 0);

}

// TEST comp_EQUAL
TEST(BinaryStore, comp_EQUAL) {
	BinaryStore x;
	char byt[] = "10100110";
	char byt2[] = "10100110";
	EXPECT_TRUE(x.comp_EQUAL(byt, byt2));
}

// TEST comp_EQUAL1
TEST(BinaryStore, comp_EQUAL1) {
	BinaryStore x;
	char byt[] = "10101110";
	char byt2[] = "10101010";
	EXPECT_FALSE(x.comp_EQUAL(byt, byt2));
}

// TEST comp_OR
TEST(BinaryStore, comp_OR) {
	BinaryStore x;
	char byt[] = "11101011";
	char byt2[] = "10101011";
	EXPECT_EQ(strcmp(x.comp_OR(byt, byt2), "11101011"), 0);
}

// TEST comp_AND
TEST(BinaryStore, comp_AND) {
	BinaryStore x;
	char byt[] =  "10111110";
	char byt2[] = "10110010";
	EXPECT_TRUE(strcmp(x.comp_AND(byt, byt2), "10110010") == 0);
}

// TEST comp_AND1
TEST(BinaryStore, comp_AND1) {
	BinaryStore x;
	char byt[] =  "11101011";
	char byt2[] = "10101011";
	EXPECT_TRUE(strcmp(x.comp_AND(byt, byt2), "10101011") == 0);
}

// TEST comp_NOT
TEST(BinaryStore, comp_NOT) {
	BinaryStore x;
	char byt[] = "00000001";
	char byt2[] = "01110101";
	EXPECT_TRUE(strcmp(x.comp_NOT(byt), "11111110") == 0);
	EXPECT_TRUE(strcmp(x.comp_NOT(byt2), "10001010") == 0);
}

// QUESTION 4
// Demo of file.

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

