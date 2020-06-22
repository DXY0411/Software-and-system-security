# Generated by Django 3.0.4 on 2020-03-25 05:23

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Course',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100, verbose_name='课程名')),
                ('number', models.IntegerField(default=0, verbose_name='编号')),
                ('summary', models.CharField(max_length=500, null=True, verbose_name='摘要')),
            ],
        ),
        migrations.CreateModel(
            name='Student',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('class_name', models.CharField(blank=True, max_length=100, null=True, verbose_name='班级')),
                ('name', models.CharField(blank=True, max_length=100, null=True, verbose_name='姓名')),
                ('number', models.IntegerField(default=0, verbose_name='学号')),
                ('phone_number', models.CharField(max_length=11, null=True, verbose_name='手机号')),
            ],
        ),
        migrations.CreateModel(
            name='Score',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('score', models.FloatField(null=True, verbose_name='成绩')),
                ('course', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='students', to='edu_admin.Course', verbose_name='课程')),
                ('student', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='my_courses', to='edu_admin.Student', verbose_name='学生')),
            ],
        ),
    ]
