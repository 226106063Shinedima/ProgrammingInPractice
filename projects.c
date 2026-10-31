#include <stdio.h>
#include <string.h>
#include "records.h"
#include "projects.h"
#include "utilities.h"
Project projects[MAX_RECORDS];
int projectCount = 0;
void addProject(void)
{
    int id;
    int i;
    int duplicate = 0;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
    if (projectCount >= MAX_RECORDS)
    {
        printf("Project list is full.\n");
        return;
    }
    printf("Enter project ID: ");
    id = readInt();
    for (i = 0; i < projectCount; i++)
    {
        if (projects[i].id == id)
        {
            duplicate = 1;
        }
    }
    if (duplicate == 1)
    {
        printf("A project with ID %d already exists.\n", id);
        return;
    }
    printf("Enter project title: ");
    readString(title, sizeof(title));
    printf("Enter project budget: ");
    budget = readDouble();
    printf("Start date - day: ");
    startDate.day = readInt();
    printf("Start date - month: ");
    startDate.month = readInt();
    printf("Start date - year: ");
    startDate.year = readInt();
    printf("End date - day: ");
    endDate.day = readInt();
    printf("End date - month: ");
    endDate.month = readInt();
    printf("End date - year: ");
    endDate.year = readInt();
    if (budget < 0)
    {
        printf("Budget cannot be negative.\n");
        return;
    }
    if (isValidDate(startDate) == 0 || isValidDate(endDate) == 0)
    {
        printf("One of the dates is not valid. Project not added.\n");
        return;
    }
    if (dateIsBefore(endDate, startDate) == 1)
    {
        printf("The end date is before the start date. Project not added.\n");
        return;
    }
    projects[projectCount].id = id;
    strcpy(projects[projectCount].title, title);
    projects[projectCount].budget = budget;
    projects[projectCount].startDate = startDate;
    projects[projectCount].endDate = endDate;
    projectCount++;
    printf("Project added.\n");
}
void displayProjects(void)
{
    int i;
    if (projectCount == 0)
    {
        printf("No projects have been added yet.\n");
        return;
    }
    printf("\n%-6s %-25s %14s %12s %12s\n", "ID", "Title", "Budget (N$)", "Start", "End");
    printf("---------------------------------------------------------------------\n");
    for (i = 0; i < projectCount; i++)
    {
        printf("%-6d %-25s %14.2f %02d/%02d/%d %02d/%02d/%d\n",
               projects[i].id, projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month,
               projects[i].endDate.year);
    }
}
int getProjectCount(void)
{
    return projectCount;
}
void saveProjects(void)
{
    FILE *fp;
    int i;
    fp = fopen("data/projects.txt", "w");
    if (fp == NULL)
    {
        perror("data/projects.txt");
        return;
    }
    for (i = 0; i < projectCount; i++)
    {
        fprintf(fp, "%d|%s|%.2f|%d|%d|%d|%d|%d|%d\n", projects[i].id,
                projects[i].title, projects[i].budget,
                projects[i].startDate.day, projects[i].startDate.month,
                projects[i].startDate.year,
                projects[i].endDate.day, projects[i].endDate.month,
                projects[i].endDate.year);
    }
    fclose(fp);
    printf("%d project(s) saved to data/projects.txt\n", projectCount);
}
void loadProjects(void)
{
    FILE *fp;
    fp = fopen("data/projects.txt", "r");
    if (fp == NULL)
    {
        printf("No saved project file found (data/projects.txt).\n");
        return;
    }
    projectCount = 0;
    while (projectCount < MAX_RECORDS &&
           fscanf(fp, "%d|%39[^|]|%lf|%d|%d|%d|%d|%d|%d",
                  &projects[projectCount].id,
                  projects[projectCount].title,
                  &projects[projectCount].budget,
                  &projects[projectCount].startDate.day,
                  &projects[projectCount].startDate.month,
                  &projects[projectCount].startDate.year,
                  &projects[projectCount].endDate.day,
                  &projects[projectCount].endDate.month,
                  &projects[projectCount].endDate.year) == 9)
    {
        projectCount++;
    }
    fclose(fp);
    printf("%d project(s) loaded from data/projects.txt\n", projectCount);
}