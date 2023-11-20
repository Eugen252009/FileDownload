import fs from "fs"
import { arrayBuffer } from "stream/consumers"
import { WritableStream } from "stream/web"
const url = "https://lupricht.net/picture.jpg"
const filename = "picture.jpg"
async function main() {
	const w = fs.createWriteStream(filename)
	const res = await fetch(url)
	const buf = await Buffer.from(await res.arrayBuffer())
	await w.write(buf)


}
main().catch((err) => console.log(err))
