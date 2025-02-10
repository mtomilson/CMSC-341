// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"
class Tester
{
public:
    bool testStudentAveErrorCase(); // done
    bool copyAnEmptyObject(); // done
    bool testNegativeItemsOrStudents();// done
    bool testConstructor();// done
    bool testCopyConstructor();// done
    bool testAssignmentOperator();// done
    bool testAssignmentOperatorEdge();// done

    void testStudentAverage();

    bool testInsertSection();// done
    bool testInsertSectionEdge();

    void testRemoveSection();
    /******************************************
     * Test function declarations go here! *
     ******************************************/
};
int main()
{   
    Tester tester;
    if (tester.copyAnEmptyObject())
    {
        cout << "Success! Copy an empty object successfully copied an empty object." << endl;
    }
    else
    {
        cout << "Failed! Copy an empty object failed to copy an empty object" << endl;
    }

    if (tester.testNegativeItemsOrStudents())
    {
        cout << "Success! Created an empty object when trying to insert negative grading items or students." << endl;
    }
    else
    {
        cout << "Failed! Did not create an empty object when trying to insert negative grading items or students." << endl;
    }

    if (tester.testConstructor())
    {
        cout << "Success! Constructor successfully created the object" << endl;
    }
    else
    {
        cout << "Failure! Constructor did not successfully create the object" << endl;
    }

    if (tester.testCopyConstructor())
    {
        cout << "Success! Copy constructor successfully copied the object." << endl;
    }
    else
    {
        cout << "Failed! Copy Constructor did not successfully copy the object." << endl;
    }

    if (tester.testAssignmentOperator())
    {
        cout << "Success! Assignment operator successfully copied the object." << endl;
    }
    else
    {
        cout << "Failed! Assignment operator did not successfully copy the object." << endl;
    }

    if (tester.testAssignmentOperatorEdge())
    {
        cout << "Success! Assignment operator successfully copied an empty object" << endl;
    }
    else
    {
        cout << "Failed! Assignment operator did not successfully copy the empty object" << endl;
    }

    if(tester.testInsertSection()) {
        cout << "Success! Section successfully inserted into the course" << endl;
    }
    else {
        cout << "Failed! Section was not successfully inserted into the course" << endl;
    }

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

bool Tester::copyAnEmptyObject()
{
    Section testObject;
    Section emptyObject = testObject;

    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testNegativeItemsOrStudents()
{
    Section testObject(123, "teacher", -10, -5);
    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testConstructor()
{
    // testing for normal case

    Section section(142, "Instructor Tom", 5, 5);
    if (section.m_instructor == "Instructor Tom" && section.m_sectionID == 142 && section.m_numGradingItems == 5 && section.m_numStudents == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testCopyConstructor()
{

    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();
    Section copiedSection(testSection);
    if (testSection.m_section == copiedSection.m_section)
    {
        return false; // testSection's m_section address should not equal copiedsection's m_section's address.
    }

    for (int i = 0; i < testSection.m_numStudents; i++)
    {
        for (int j = 0; j < testSection.m_numGradingItems; j++)
        {
            if (testSection.m_section[i][j] != copiedSection.m_section[i][j])
            {
                return false; // fail fast, if one of them doesn't equal then return false
            }
        }
    }

    if (testSection.m_instructor == copiedSection.m_instructor && testSection.m_numGradingItems == copiedSection.m_numGradingItems && testSection.m_sectionID == copiedSection.m_sectionID && testSection.m_numStudents == copiedSection.m_numStudents)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testAssignmentOperator()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();
    Section copiedSection;
    copiedSection = testSection;

    if (testSection.m_section == copiedSection.m_section)
    {
        return false; // testSection's m_section address should not equal copiedsection's m_section's address.
    }

    for (int i = 0; i < testSection.m_numStudents; i++)
    {
        for (int j = 0; j < testSection.m_numGradingItems; j++)
        {
            if (testSection.m_section[i][j] != copiedSection.m_section[i][j])
            {
                return false; // fail fast, if one of them doesn't equal then return false
            }
        }
    }

    if (testSection.m_instructor == copiedSection.m_instructor && testSection.m_numGradingItems == copiedSection.m_numGradingItems && testSection.m_sectionID == copiedSection.m_sectionID && testSection.m_numStudents == copiedSection.m_numStudents)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testAssignmentOperatorEdge()
{
    Section testObject;
    Section emptyObject;
    testObject = emptyObject;

    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tester::testInsertSection()
{
    Course course(1);
    course.insertSection(142, "Instructor Tom", 5, 3);

    if (course.m_course[0]->m_instructor == "Instructor Tom" && course.m_course[0]->m_sectionID == 142 && course.m_course[0]->m_numGradingItems == 5 && course.m_course[0]->m_numStudents == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Tester::testStudentAverage()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();

    double average = testSection.studentAverage(1);
    testSection.dump();
    cout << "Average of Student 3: " << average << endl;
}

void Tester::testRemoveSection()
{
    Course testCourse(4);
    testCourse.insertSection(142, "test", 2, 2);
    testCourse.insertSection(122, "testt", 1, 2);
    testCourse.insertSection(143, "testtt", 2, 2);
    testCourse.insertSection(141, "testttt", 3, 2);

    testCourse.removeSection(143);

    testCourse.insertSection(133, "Tester", 2, 4);
    testCourse.displaySections();
}