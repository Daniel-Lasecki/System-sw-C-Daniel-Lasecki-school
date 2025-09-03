# System Software (with C)

## Overview of course setup

For System SW course works you need to have 
1. Lab VM running on VirtualBox: VM provides standardised development toolchain and IDE.
2. TUAS gitlab account and working git skills (developed alongside the course). Course exercise instructions and files are distributed from this repository, and you will return your work into your personal forked return repository.

## The environment setup

Wait until you go through the environment setup in object oriented programming (OOP) course, the same setup is used on this course. 

In case you are not taking that course or you missed the instructions there, then follow the steps below.

### Step 1: Install VM

Download VM image (you get the image in OOP course).
- If you are not taking that course, download the image here (link is valid until the end of September): https://filesender.funet.fi/?s=download&token=a833d7b5-b193-4fe6-8987-b92ea19dfa9f
Import VM to VirtualBox (install VirtualBox before that).
Modify configuration:
- The default "NAT" network is recommended.
- Check the amount of CPU cores and memory allocated for the VM. 2 cores + 4GB RAM should do, but double that amount is better.
- VM default user/passwd is student/student
Check that you can start the VM, log in and have Ubuntu desktop running with internet connectivity.

### Step 2: Fork lab repository

Log into TUAS gilab https://git.dc.turkuamk.fi/ and in main menu, switch to Groups / `TUAS SystemSW`. (If `TUAS SystemSW` is not shown, ask instructor to add you to that group). In that group there is repository `Systemsw Lab Exercises`. Create a private <b>fork</b> to your personal namespace. A fork is a copy of a project. Forking a repository allows you to make changes without affecting the original project. This forked project works as your return repository.  
- add user `sanna määttä` to the project with "Developer" role.
- add tag 'SystemSW-2025Fall' to your repository: In gitlab Settings->General, "Topics"

### Step 3: Customize VM

** Note: If you already have a working git account (in dc.turkuamk.fi), you don't have to do this again **

The installed VM is naturally the same for all students, but will want to use your own identity to sync with TUAS gitlab repository. 
- Configure git identity (obviously use your name and e-mail address)
```bash
   student@student-VirtualBox:~$ git config --global user.name "Mona Lisa"
   student@student-VirtualBox:~$ git config --global user.email "YOUR_EMAIL@edu.turkuamk.fi"
```
- Create keypair for the VM:
```bash
   student@student-VirtualBox:~$ ssh-keygen -t rsa -b 2048 -f /home/student/.ssh/id_rsa -q -N ""
```
- Copy your public key to your forked project in TUAS gitlab: print your public key on terminal, copy content and paste to TUAS gitlab in browser (top left corner menu box and top-right icon in there, "Edit profile / SSH Keys").
```bash
   student@student-VirtualBox:~$ cat /home/student/.ssh/id_rsa.pub
```
- (Change passwd for student on VM)

### Step 4: Clone your remote repository to your VM



```bash
   student@student-VirtualBox:~$ git clone git@git.dc.turkuamk.fi:YOUR-NAMESPACE/systemsw_lab_exercises.git
```
If gitlab asks for credentials, then your SSH keys setting has failed.  
You should now have a local git repository containing all lab assignments and files, linked to a private remote repository in TUAS gitlab. 

### Step 5: git + gitlab skills

All your lab work will end up in your git repository, so it is necessary develop git skills as well.  
Check the material and exercises [on this page](git_tutorial.md)

