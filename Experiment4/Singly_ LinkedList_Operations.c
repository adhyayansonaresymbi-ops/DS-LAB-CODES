#include <stdio.h>
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert(list, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(list, position);
                break;
            case 3:
                reverse(list);
                printf("Reversed List: ");
                displayReversed(list);
                reverse(list); 
                break;
            case 4:
                printf("Linked List: ");
                display(list);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
