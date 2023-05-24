# Dashboard Mobile Application
 
We will use GIT for the version control of our project, this will make it possible to develop with other developers on the same project and be able to combine the result of our changes.

We will make use of different branches to keep different versions of our project active. These can be used for having different states of the project active; completely working, in development, in progress feature or a bug fix. The way these branches get merged will follow a certain pipeline.

## Pipeline

To always maintain a steady version of the project we will only push to master branch with version of the project that are tested and don’t have any bugs. We will use Development as a branch that finished features get pushed to. This branch can be used to test out the combination of different features and make sure they still work. It also serves as an intermediate step between master and feature/ branch.

| Definitions | Explanation |
| ------ | ------ |
| Protected branch | These branches can’t be pushed to from the client. These can only be pushed using a pull request that’s approved |
| Pull request (PR) | You can open a pull request from Bitbucket, here you can select the branch you want to merge to and from. |

| Name (prefix) | What it’s for | Relation with other branches |
| ------ | ------ | ------ |
| master | Should always contain a fully functioning version of the program | Will get updated from Development after testing has come out positive |
| development | Contains the in progress state of the program. This should be the latest version and should be (but doesn’t guarantee) a working version | Gets updated with a pull request from feature/ and bug/ branches |
| feature/ | This is a prefix used for branches that are created for making a feature. What’s written after the / should be a descriptive name of the feature | When this feature is finished a pull request should be opened to development so it can be pushed to it (after approval.) |
| bug/ | This is a prefix used for branches that are created for fixing a bug. What’s written after the / should be a descriptive name of the bug |When this bug is fixed a pull request should be opened to development so it can be pushed to it (after approval.) |

## Commit agreements
### General

Every commit should be written in English language and have correct spelling, punctuation and capitalization.

### Structure

The commit message should be structured as follows;
```sh
<type> <issue>: [description]
[body(optional)]
```


### Definitions

| Element | Explanation | Examples |
| ------ | ------ | ------ |
| **\<type>** | What type of change has this made to the app. | - ```fix```: e.g. a bug fix. <br> - ```feat:``` a new feature that has been added. <br> - ```minor```: a change to an existing feature. <br> - ```import```: added new content to the project. |
| **\<issue>** | The issue where the need for this change is from. This number can be gotten from the issue you’re currently working on. | - ```TJALK-22``` <br> - ```TJALK-35``` <br> - ```TJALK-22: Create technical design document.``` |
| **[description]** | Small explanation of what changed in this commit. This should make sense based on the ```<type>```. Generally these should be 1 sentence. If it’s more think about describing it in the ```[body]``` | ```Fixed bug where the data wouldn't update if in the Bilge screen.``` <br> <br> ```Introduced feature to display last time since Engine start.``` |
| **[body]** | Large explanation of the change, these will be most appropriate for big changes. This will be most common for ```feat``` type commits. Generally these should be 2 or more sentences. | ```Setup structure from the UML, this includes systems for the Data graphs generation back-end and front end. Art has been added for this as well with applied settings.``` |
| **(optional)** | A tag for other elements that describes whether they are mandatory in the commit structure | ```[body(optional)]``` |

Example commits

```yml
feat PIPET-22: Added function for start button.
```
```yml
minor PIPET-105: Updated table generation for more fluid results.
Changed the generated lines to curve from point to point.
Updated the amount of data points that can be shown
from 50 to 80.
```

Sources

https://www.conventionalcommits.org/en/v1.0.0/

## License

Unless stated otherwise all works are:

-   Copyright © 2023+ [Martin Keesom](https://martinkeesom.nl/)
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzNTA0NTc5ODAsLTEzMzUyMTIzODddfQ
==
-->
