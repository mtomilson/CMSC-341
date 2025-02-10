// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"
class Tester
{
public:
    bool testStudentAveErrorCase();
    void copyAnEmptyObject();
    void testNegativeItemsOrStudents();
    void testConstructor();
    void testCopyConstructor();
    void testAssignmentOperator();
    void testAssignmentOperatorEdge();
    void testStudentAverage();
    void testRemoveSection();
    /******************************************
     * Test function declarations go here! *
     ******************************************/
};
int main()
{
    //the following is a sample usage of the Section class
    // cout << "the following is a sample usage of the Section class:" << endl;
    // Section * aSection = new Section(1000,"John Smith", 8, 8);
    // aSection->simulateData();
    // aSection->dump();
    // cout << endl;
    // // the following is a sample usage of the Course class
    // cout << "the following is a sample usage of the Course class:" << endl;
    // Course aCourse(3);
    // aCourse.insertSection(aSection);
    // aCourse.insertSection(2000,"Prof Smith", 9, 8);
    // aCourse.insertSection(3000,"Prof John", 8, 9);
    // Section * section = aCourse.getSection(4000);
    // if (section != nullptr)
    //     section->dump();
    // else
    //     cout << "Section 4000 does not exist!" << endl;

    // Tester tester;
    // // testing error case for calculation of student average
    // cout << "\nTesting studentAverage(...) for an error case:\n\n";
    // if (tester.testStudentAveErrorCase() == true)
    //     cout << "\tError case (student index does not exist) of studentAverage() passed!\n";
    // else
    //     cout << "\tError case (student index does not exist) of studentAverage() failed!\n";
    // cout << endl;

    

    return 0;
}

bool Tester::testStudentAveErrorCase()
{
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject(1000, "John Smith", 10, 1);
    testObject.simulateData();
    double average = testObject.studentAverage(1); // out of range index
    if (average == 0.0)                            // expected output
        result = true;
    else
        result = false;
    return result;
}

void Tester::copyAnEmptyObject()
{
    Section testObject;
    Section emptyObject = testObject;

    emptyObject.dump();
}

void Tester::testNegativeItemsOrStudents()
{
    Section testSection(123, "teacher", -10, -5);
    testSection.displayMemberVariables();
}

void Tester::testConstructor()
{
    // testing for normal case

    Section section(142, "Instructor Tom", 5, 5);
    section.simulateData();
    section.displayMemberVariables();
    section.dump();
}

void Tester::testCopyConstructor()
{

    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();
    Section copiedSection(testSection);
    testSection.displayMemberVariables();
    testSection.dump();
    copiedSection.displayMemberVariables();
    copiedSection.dump();
}

void Tester::testAssignmentOperator()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    Section copiedSection;
    testSection.simulateData();
    copiedSection = testSection;
    testSection.displayMemberVariables();
    testSection.dump();
    copiedSection.displayMemberVariables();
    copiedSection.dump();
}

void Tester::testAssignmentOperatorEdge()
{
    Section testSection;
    Section copiedSection;
    copiedSection = testSection;
    testSection.displayMemberVariables();
    testSection.dump();
    copiedSection.displayMemberVariables();
    copiedSection.dump();
}

void Tester::testStudentAverage()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();

    double average = testSection.studentAverage(1);
    testSection.dump();
    cout << "Average of Student 3: " << average <<  endl;
}

void Tester::testRemoveSection() {
    Course testCourse(4);
    testCourse.insertSection(142, "test", 2,2);
    testCourse.insertSection(122, "testt", 1,2);
    testCourse.insertSection(143, "testtt", 2,2);
    testCourse.insertSection(141, "testttt", 3,2);

    testCourse.removeSection(143);

    testCourse.insertSection(133,"Tester", 2, 4);
    testCourse.displaySections();





}