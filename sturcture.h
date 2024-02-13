#pragma once
const int SUBJECT_NAME_LENGTH = 30;

const int STUDENT_NAME_LENGTH = 30;

const int GROUP_NAME_LENGTH = 10;

struct Student {
    char surname[STUDENT_NAME_LENGTH];
    char name[STUDENT_NAME_LENGTH];
    char group[GROUP_NAME_LENGTH];
    int math;
    int physics;
    int english;
    int ukrainian;
};