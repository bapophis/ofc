* ofc\_file\_s has to be split (if it's used at all) because of members unsigned ref, language options, size (at least)

* ast\_file\_s contains path, file include list, parent pointer to ast\_file\_s, strings
thus to export the ast relvant info for a file, access with file.ast, from a file list: list-\>file[i].ast
* ast\_label\_s contains

* concentrating more on sema scope, we should initially take a minimalistic view of the AST and try to extend afterwards
