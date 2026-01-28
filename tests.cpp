#include "TestFramework.h"
#include "Task.h"
#include "TaskManager.h"
#include "Validator.h"
#include <ctime>

void testTaskCreation() {
    time_t dueDate = time(nullptr) + 86400; // Tomorrow
    Task task(1, "Test Task", "Test Description", Priority::HIGH, dueDate);
    
    ASSERT_EQUAL(1, task.getId());
    ASSERT_TRUE(task.getTitle() == "Test Task");
    ASSERT_TRUE(task.getPriority() == Priority::HIGH);
    ASSERT_TRUE(task.getStatus() == Status::PENDING);
}

void testTaskTags() {
    time_t dueDate = time(nullptr) + 86400;
    Task task(2, "Tagged Task", "Description", Priority::MEDIUM, dueDate);
    
    task.addTag("urgent");
    task.addTag("work");
    
    ASSERT_TRUE(task.hasTag("urgent"));
    ASSERT_TRUE(task.hasTag("work"));
    ASSERT_FALSE(task.hasTag("personal"));
    
    task.removeTag("urgent");
    ASSERT_FALSE(task.hasTag("urgent"));
}

void testTaskCategory() {
    time_t dueDate = time(nullptr) + 86400;
    Task task(3, "Categorized Task", "Description", Priority::LOW, dueDate);
    
    task.setCategory("Work");
    ASSERT_TRUE(task.getCategory() == "Work");
}

void testValidatorNotEmpty() {
    ASSERT_TRUE(Validator::isNotEmpty("Hello"));
    ASSERT_FALSE(Validator::isNotEmpty(""));
    ASSERT_FALSE(Validator::isNotEmpty("   "));
}

void testValidatorLength() {
    ASSERT_TRUE(Validator::isValidLength("Test", 1, 10));
    ASSERT_FALSE(Validator::isValidLength("Test", 5, 10));
    ASSERT_FALSE(Validator::isValidLength("This is a very long string", 1, 10));
}

void testValidatorTrim() {
    ASSERT_TRUE(Validator::trim("  hello  ") == "hello");
    ASSERT_TRUE(Validator::trim("world") == "world");
    ASSERT_TRUE(Validator::trim("   ") == "");
}

void testValidatorTaskId() {
    ASSERT_TRUE(Validator::isValidTaskId(1));
    ASSERT_TRUE(Validator::isValidTaskId(100));
    ASSERT_FALSE(Validator::isValidTaskId(0));
    ASSERT_FALSE(Validator::isValidTaskId(-1));
}

void testValidatorEmail() {
    ASSERT_TRUE(Validator::isValidEmail("test@example.com"));
    ASSERT_TRUE(Validator::isValidEmail("user.name@domain.co.uk"));
    ASSERT_FALSE(Validator::isValidEmail("invalid.email"));
    ASSERT_FALSE(Validator::isValidEmail("@example.com"));
}

void testTaskPriority() {
    ASSERT_TRUE(Task::priorityToString(Priority::HIGH) == "HIGH");
    ASSERT_TRUE(Task::priorityToString(Priority::MEDIUM) == "MEDIUM");
    ASSERT_TRUE(Task::priorityToString(Priority::LOW) == "LOW");
}

void testTaskStatus() {
    ASSERT_TRUE(Task::statusToString(Status::PENDING) == "PENDING");
    ASSERT_TRUE(Task::statusToString(Status::IN_PROGRESS) == "IN_PROGRESS");
    ASSERT_TRUE(Task::statusToString(Status::COMPLETED) == "COMPLETED");
}

int main() {
    TestFramework tests;

    // Register tests
    tests.addTest("Task Creation", testTaskCreation);
    tests.addTest("Task Tags", testTaskTags);
    tests.addTest("Task Category", testTaskCategory);
    tests.addTest("Validator: Not Empty", testValidatorNotEmpty);
    tests.addTest("Validator: Length", testValidatorLength);
    tests.addTest("Validator: Trim", testValidatorTrim);
    tests.addTest("Validator: Task ID", testValidatorTaskId);
    tests.addTest("Validator: Email", testValidatorEmail);
    tests.addTest("Task Priority Conversion", testTaskPriority);
    tests.addTest("Task Status Conversion", testTaskStatus);

    // Run all tests
    return tests.runAll();
}
