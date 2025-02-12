#include "course.h"
class Tester
{
public:
    bool copyAnEmptyObject();           // done
    bool testNegativeItemsOrStudents(); // done
    bool testConstructor();             // done
    bool testCopyConstructor();         // done
    bool testAssignmentOperator();      // done
    bool testAssignmentOperatorEdge();  // done
    bool testStudentAverage();          // done
    bool testInsertSection();           // done
    bool testInsertSectionEdge();       // done
    bool testInsertSectionError();
    bool testFullInsertSection();
    bool testInsertSectionObject();
    bool testInsertSectionObjectEdge();
    bool testRemoveSection(); // done
    bool testClassAverage();
    bool testCourseAverage();

    bool testTestAverage();
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

    if (tester.testInsertSection())
    {
        cout << "Success! Section successfully inserted into the course" << endl;
    }
    else
    {
        cout << "Failed! Section was not successfully inserted into the course" << endl;
    }

    if (!tester.testInsertSectionEdge())
    {
        cout << "Success! Insert Section did not insert a section with an existing ID in the course." << endl;
    }
    else
    {
        cout << "Failed! Insert Section inserted a section with an existing ID in the course." << endl;
    }

    if (tester.testStudentAverage())
    {
        cout << "Success! Student Average successfully calculated the average of the student" << endl;
    }
    else
    {
        cout << "Failed! Student Average did not calculate the average correctly" << endl;
    }

    if (tester.testRemoveSection())
    {
        cout << "Success! Remove Section successfully removed the section" << endl;
    }
    else
    {
        cout << "Failed! Remove Section did not remove the section" << endl;
    }
    if (tester.testInsertSectionObject())
    {
        cout << "Success! Insert section using an object successfully added!" << endl;
    }
    else
    {
        cout << "Failed! Insert section using an object did not successfully add" << endl;
    }

    if (tester.testInsertSectionObjectEdge())
    {
        cout << "Success! Insert section did not insert the object" << endl;
    }
    else
    {
        cout << "Failed! Insert section inserted the object." << endl;
    }

    if (tester.testInsertSectionError())
    {
        cout << "Success! Section was not added because there was not enough students and/or items" << endl;
    }
    else
    {
        cout << "Failed! Section was added with 0 items and/or students." << endl;
    }

    if (!tester.testFullInsertSection())
    {
        cout << "Success! Section was not added because the course was full" << endl;
    }
    else
    {
        cout << "Failed! Section was added even though the course was full" << endl;
    }

    if (tester.testCourseAverage())
    {
        cout << "Success! Course average was calculated properly" << endl;
    }
    else
    {
        cout << "Failed! Course average was not calculated properly" << endl;
    }

    if (tester.testTestAverage())
    {
        cout << "Success! Properly calculated the average of the test" << endl;
    }
    else
    {
        cout << "Failed! Did not properly calculate the average of the test" << endl;
    }

    if (tester.testClassAverage())
    {
        cout << "Success! Properly calculateed the average of the class" << endl;
    }
    else
    {
        cout << "Failed! Did not properly calculate the average of the class" << endl;
    }

    return 0;
}

// tests the copy constructor for an edge case where it copies an empty object

bool Tester::copyAnEmptyObject()
{
    Section testObject;
    Section emptyObject(testObject);

    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tests the overloaded constructor of section to see if it creates an empty object when a negative amount of students
// or items were added

bool Tester::testNegativeItemsOrStudents()
{
    Section testObject(123, "teacher", -10, -5);
    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tests the overloaded constructor of section to see if it properly creates a section with the overloaded data

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

// tests the copy constructor to see if it properly copies the given data

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

// tests the assignment operator to see if it properly copies the given data

bool Tester::testAssignmentOperator()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();
    Section copiedSection;
    copiedSection = testSection;

    if (testSection.m_section == copiedSection.m_section)
    {
        return false; // testSection's m_section address should not equal copied section's m_section's address.
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

// tests the assignment operator edge case where it assigns an object with an empty object

bool Tester::testAssignmentOperatorEdge()
{
    Section testObject;
    Section emptyObject;
    testObject = emptyObject;

    if (testObject.m_instructor == "" && testObject.m_numGradingItems == 0 && testObject.m_numGradingItems == 0 && testObject.m_section == nullptr &&
        testObject.m_sectionID == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tests the insert section method with the overloaded constructor

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

// tests the insert section edge case where it tries to insert a section with a duplicate id

bool Tester::testInsertSectionEdge()
{
    Course course(2);
    course.insertSection(142, "Instructor Tom", 5, 3);
    if (course.insertSection(142, "Instructor Joe", 5, 2))
    { // trying to insert a section with the same id
        return true;
    }
    else
    {
        return false;
    }
}

// tests the student average method to see if it calculates the proper average

bool Tester::testStudentAverage()
{
    Section testSection(142, "Instructor Tom", 5, 3);
    testSection.simulateData();
    double average = testSection.studentAverage(0);
    if (average == 53.028) // predetermined average after seeing the data values inputted.
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tests the removeSection method for a normal case to ensure the section got removed

bool Tester::testRemoveSection()
{
    Course testCourse(4);
    testCourse.insertSection(142, "test", 2, 2);
    testCourse.insertSection(122, "testt", 1, 2);
    testCourse.insertSection(143, "testtt", 2, 2);
    testCourse.insertSection(141, "testttt", 3, 2);

    testCourse.removeSection(143);

    if (!testCourse.getSection(143))
    { // if getSection() returns true then the section was not removed properly
        return true;
    }
    else
    {
        return false;
    }
}

// tests the insert section method with a pointer to a section object

bool Tester::testInsertSectionObject()
{
    Course testCourse(4);
    Section *section = new Section(142, "test", 2, 2);

    testCourse.insertSection(section);

    if (testCourse.getSection(142))
    { // if testcourse.getsection returns true then it successfully found the section we just added.
        return true;
    }
    else
    {
        return false;
    }
}

// tests the insertsection object edge case to ensure that duplicate id's are not inserted

bool Tester::testInsertSectionObjectEdge()
{
    Course testCourse(2);
    Section *section1 = new Section(142, "Instructor Tom", 5, 5);
    Section *section2 = new Section(142, "Instructor Phil", 1, 2);

    testCourse.insertSection(section1);
    if (testCourse.insertSection(section2))
    {
        return false; // if the if statement is true then it was successfully added, therefore we return false because
    } // it shouldn't have been added.
    else
    {
        return true;
    }
}

// tests insert section error case when inserting a section with 0 students and or 0 items, this shouldn't insert.

bool Tester::testInsertSectionError()
{
    Course course(2);
    course.insertSection(142, "professor", 0, 0); // error, cannot add section with 0 grading items or 0 students

    if (!course.getSection(142))
    {
        return true; // if getSection() returns false then it wasn't able to be found therefore it wasn't added.
    }
    else
    {
        return false;
    }
}

// tests error case for insertsection where the course is full and tries to insert another section

bool Tester::testFullInsertSection()
{
    Course course(2);
    course.insertSection(142, "professor", 1, 2);
    course.insertSection(111, "professor hello", 2, 1);

    return course.insertSection(123, "Professor test", 2, 1); // should return false because there's not enough space.
}

// tests the courseAverage method where it tests the courseaverage method

bool Tester::testCourseAverage()
{
    Course course(2);
    course.insertSection(142, "professor", 3, 2);
    course.insertSection(121, "professor hill", 2, 2);
    course.getSection(142)->simulateData();
    course.getSection(121)->simulateData();
    if (course.courseAverage() == 47.446) // calculated value from the randomized data
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tests the testaverage method

bool Tester::testTestAverage()
{
    Course course(1);
    course.insertSection(142, "professor tom", 2, 2);
    course.getSection(142)->simulateData();
    if (course.getSection(142)->testAverage(1) == 66.32) // predetermined value calculated from the randomized data
    {
        return true;
    }
    else
    {
        return false;
    }
}

//tests the classAverage() method of section for a normal case

bool Tester::testClassAverage()
{
    Section section(142, "professor", 2, 2);
    section.simulateData();
    if (section.classAverage() == 51.7025)
    {
        return true;
    }
    else
    {
        return false;
    }
}
